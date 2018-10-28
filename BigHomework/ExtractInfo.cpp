#include "ExtractInfo.h"

#include <io.h>
#include <fstream>

const NewsInfo extractInfo(const CharString & HTMLfilename) {
    CharString filePath;
    filePath = L".\\input\\";
    filePath.concat(HTMLfilename);

    std::wifstream HTMLfile(filePath.wstring());
    std::locale loc(".936");
    HTMLfile.imbue(loc);

    std::wstring line;
    CharString csLine;

    NewsInfo info;
    Stack<CharString> label;
    InfoType infoType = NONE;
    bool record = false;
    bool newParagraph = false;
    bool endOf = false;
    bool skip = false;

    while (!HTMLfile.eof()) {
        std::getline(HTMLfile, line);
        if (line.empty()) {
            continue;
        }
        csLine = line;
        parseLine(csLine, info, label, infoType,
            record, newParagraph, endOf, skip);
        if (endOf) {
            break;
        }
    }
    HTMLfile.close();

    info.postProcess();
    return info;
}

Stack<CharString> getHTMLList() {
    Stack<CharString> HTMLlist;
    CharString path;
    path = L".\\input\\*.html";

    long hFile = 0;
    struct _wfinddata_t fileData;
    const wchar_t * dirPath = path.wchar();
    if ((hFile = _wfindfirst(dirPath, &fileData)) != -1) {
        do {
            CharString HTMLname;
            HTMLname = fileData.name;
            HTMLlist.push(HTMLname);
        } while (_wfindnext(hFile, &fileData) == 0);
        _findclose(hFile);
    }
    return HTMLlist;
}

void extractInfoInAllPages() {
    // ��ȡ���е�.html�ļ���
    Stack<CharString> HTMLlist = getHTMLList();

    std::cout << "Extract info from ..." << std::endl;

    while (!HTMLlist.empty()) {
        // ��ջ���ļ����н�����������
        CharString HTMLfilename = HTMLlist.top();
        std::wcout << HTMLfilename << std::endl;
        NewsInfo newsInfo = extractInfo(HTMLfilename);
        saveNewsInfo(newsInfo, HTMLfilename);
        HTMLlist.pop();
    }
}

void parseLine(const CharString & line,
    NewsInfo & info,
    Stack<CharString>& labelStack,
    InfoType & infoType,
    bool & record,
    bool & newParagraph,
    bool & endOf, 
    bool & skip) {

    int rightIndex = 0;
    bool isLabel = false;
    CharString processedLine = line;

    while (true) {
        // ����Ǳ�ǩ����Ӧ���� < ��ʼ
        if (processedLine[0] == L'<') {
            rightIndex = processedLine.indexOf(L'>');
            isLabel = true;
        }
        // �������ı�
        else {
            rightIndex = processedLine.indexOf(L'<');
            isLabel = false;
        }

        bool breakLater = false;
        if (rightIndex == -1
            || rightIndex == processedLine.length() - 1) {
            breakLater = true;
        }

        // ��ȡ����ǩ�������д���
        if (isLabel && rightIndex > 1) {
            CharString label = processedLine.subString(1, rightIndex).trim();
            processLabel(label, labelStack, infoType, record, newParagraph, skip);
        }
        // ��ȡ���ı��������д���
        else if (!isLabel) {
            CharString text;
            if (rightIndex > 0) {
                text = processedLine.subString(0, rightIndex).trim();
            }
            else {
                text = processedLine.trim();
            }
            if (record && !skip) {
                processText(text, info, infoType, newParagraph, endOf);
            }
        }

        // ��ǰ��ȥ���Ѿ�����������ݣ������²��ֽ��������Ĵ���
        if (isLabel && rightIndex + 1 < processedLine.length()
            && rightIndex > 0) {
            processedLine = processedLine.subString(rightIndex + 1).trim();
            rightIndex = 0;
        }
        else if (!isLabel && rightIndex < processedLine.length()
            && rightIndex > 0) {
            processedLine = processedLine.subString(rightIndex).trim();
            rightIndex = 0;
        }

        if (breakLater) {
            rightIndex = 0;
            break;
        }
    }
}

LabelType determineLabelType(const CharString & label) {
    int len = label.length();
    if (label[len - 1] == L'/') {
        return SINGLE;
    }
    else if (label[0] == L'!') {
        return NOTATION;
    }
    else {
        return PAIR;
    }
}

void processLabel(const CharString & label,
    Stack<CharString>& labelStack,
    InfoType & infoType,
    bool & record,
    bool & newParagraph, 
    bool & skip) {

    LabelType type = determineLabelType(label);
    bool startPairLabel = false;
    switch (type) {
    case PAIR:
        startPairLabel = (label[0] != L'/');
        // ��������ǩ��һ�Ա�ǩ�п�ʼ����һ��
        if (startPairLabel) {
            labelStack.push(label);
            InfoType info = parseStackTopLabel(label);
            // �����ǰû�м�¼�����Ҷ����˿�ʼ��¼�йصı�ǩ
            if (!record) {
                if (info != NONE
                    && info != NEW_PARAGRAPH
                    && info != SKIP) {
                    infoType = info;
                    record = true;
                }
            }
            else {
                if (info == SKIP) {
                    skip = true;
                }
            }
        }
        // ��������ǩ��һ�Ա�ǩ�н�������һ��
        else {
            // ����ƥ�������ȼ����͵ı�ǩȫ������
            while (!labelStack.empty()
                && !labelMatch(labelStack.top(), label)
                && !labelPriorer(labelStack.top(), label)) {

                InfoType info = parseStackTopLabel(labelStack.top());
                labelStack.pop();
                if (info != NONE) {
                    if (info == NEW_PARAGRAPH) {
                        if (record) {
                            newParagraph = true;
                        }
                    }
                    else if (info == SKIP) {
                        skip = false;
                    }
                    else {
                        infoType = NONE;
                        record = false;
                    }
                    
                }
            }
            // ��ƥ��ı�ǩ����
            if (!labelStack.empty()
                && labelMatch(labelStack.top(), label)) {
                InfoType info = parseStackTopLabel(labelStack.top());
                labelStack.pop();
                if (info != NONE) {
                    if (info == NEW_PARAGRAPH) {
                        if (record) {
                            newParagraph = true;
                        }
                    }
                    else if (info == SKIP) {
                        skip = false;
                    }
                    else {
                        infoType = NONE;
                        record = false;
                    }
                }
            }
        }
        break;
    // �����ǩ�ǵ���һ���ģ���ʲô������
    case SINGLE:
        break;
    // �����ǩ��ע�͵ģ���ʲô������
    case NOTATION:
        break;
    default:
        break;
    }
}

void processText(CharString & text,
    NewsInfo & info,
    const InfoType & infoType,
    bool & newParagraph,
    bool & endOf) {

    // �Բ�ͬ�ı�ǩ��������ͬ�Ĵ���
    switch (infoType) {
    case TITLE:
        info.setTitle(text);
        break;
    case TIME_AND_SOURCE:
        info.appendTimeAndSource(text);
        break;
    case CONTENT:
        if (filtText(text, endOf)) {
            if (newParagraph) {
                CharString newPara;
                newPara = L"\n";
                info.appendContent(newPara);                
            }
            info.appendContent(text);
        }    
        newParagraph = false;
        break;
    case NONE:
        break;
    default:
        break;
    }
}

bool filtText(CharString & text, bool & endOf) {
    CharString filter1;
    CharString filter2;
    CharString entityName[6];
    filter1 = L"������Դ";
    filter2 = L"���α༭";
    entityName[0] = L"&nbsp;";
    entityName[1] = L"&lt;";
    entityName[2] = L"&gt;";
    entityName[3] = L"&amp;";
    entityName[4] = L"&quot;";
    entityName[5] = L"&apos;";

    // ȥ���������ġ�������Դ���͡����α༭����
    if (text.indexOf(filter1) != -1
        || text.indexOf(filter2) != -1) {
        endOf = true;
        return false;
    }
    
    // ȥ���հ���
    if (text.blank()) {
        return false;
    }

    // ȥ��htmlʵ���ַ�
    for (int i = 0; i < 6; i++) {
        while (true) {
            int entityStart = text.indexOf(entityName[i]);
            if (entityStart != -1) {
                CharString temp;
                if (entityStart > 0) {
                    temp.concat(text.subString(0, entityStart));
                }
                if (entityStart + entityName[i].length() < text.length()) {
                    temp.concat(text.subString(entityStart + entityName[i].length()));
                }
                text = temp;
            }
            else {
                break;
            }
        }           
    }

    return true;
}

InfoType parseStackTopLabel(const CharString & label) {
    CharString titlePattern;
    CharString timeAndSourcePattern1;
    CharString timeAndSourcePattern2;
    CharString timeAndSourcePattern3;
    CharString contentPattern;
    CharString newParagraphPattern;
    CharString stylePattern;
    CharString scriptPattern;

    titlePattern = L"h1";
    timeAndSourcePattern1 = L"post_time_source";
    timeAndSourcePattern2 = L"ep-time-soure";
    timeAndSourcePattern3 = L"class=\"ptime\"";
    contentPattern = L"id=\"endText\"";
    newParagraphPattern = L"p";
    stylePattern = L"style";
    scriptPattern = L"script";

    if (label.indexOf(titlePattern) == 0) {
        return TITLE;
    }
    else if (label.indexOf(timeAndSourcePattern1) != -1
        || label.indexOf(timeAndSourcePattern2) != -1
        || label.indexOf(timeAndSourcePattern3) != -1) {
        return TIME_AND_SOURCE;
    }
    else if (label.indexOf(contentPattern) != -1) {
        return CONTENT;
    }
    else if (label.indexOf(newParagraphPattern) == 0) {
        return NEW_PARAGRAPH;
    }
    else if (label.indexOf(stylePattern) == 0
        || label.indexOf(scriptPattern) == 0) {
        return SKIP;
    }
    else {
        return NONE;
    }
}

bool labelMatch(const CharString & startLabel,
    const CharString & endLabel) {

    return startLabel.indexOf(endLabel.subString(1)) != -1;
}

bool labelPriorer(const CharString & stackTopLabel,
    const CharString & currentLabel) {

    CharString divLabel;
    divLabel = L"div";

    if (stackTopLabel.indexOf(divLabel) != -1) {
        return true;
    }
    return false;
}

void saveNewsInfo(const NewsInfo & newsInfo,
    const CharString & HTMLfilename) {

    CharString filePath;
    filePath = L".\\output\\";
    CharString postfix;
    postfix = L".info";
    CharString HTMLfilePostfix;
    HTMLfilePostfix = L".html";

    filePath.concat(HTMLfilename.
        subString(0, HTMLfilename.indexOf(HTMLfilePostfix)));
    filePath.concat(postfix);

    std::wofstream infoFile(filePath.wstring());
    std::locale loc(".936");
    infoFile.imbue(loc);

    infoFile << newsInfo.getTitle() << std::endl;
    infoFile << newsInfo.getSource() << std::endl;
    infoFile << newsInfo.getTime() << std::endl;
    infoFile << newsInfo.getContent() << std::endl;

    infoFile.close();
}
