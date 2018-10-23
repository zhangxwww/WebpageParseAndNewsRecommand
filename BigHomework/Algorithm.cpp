#include "Algorithm.h"

#include <io.h>
#include <fstream>

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

const NewsInfo parseOneNewsPage(const CharString & HTMLfilename) {
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

    while (!HTMLfile.eof()) {
        std::getline(HTMLfile, line);
        if (line.empty()) {
            continue;
        }
        csLine = line;
        parseLine(csLine, info, label, infoType, record);
    }
    return info;
}

void parseLine(const CharString & line,
    NewsInfo & info,
    Stack<CharString>& labelStack,
    InfoType & infoType,
    bool & record) {

    int rightIndex = 0;
    bool isLabel = false;
    CharString processedLine = line;

    while (true) {
        
        if (processedLine[0] == L'<') {
            rightIndex = processedLine.indexOf(L'>');
            isLabel = true;
        }
        else {
            rightIndex = processedLine.indexOf(L'<');
            isLabel = false;
        }

        bool breakLater = false;
        if (rightIndex == -1
            || rightIndex == processedLine.length() - 1) {
            breakLater = true;
        }

        if (isLabel && rightIndex > 1) {
            CharString label = processedLine.subString(1, rightIndex);
            processLabel(label, labelStack, infoType, record);
        }
        else if(!isLabel && rightIndex > 0){
            CharString text = processedLine.subString(0, rightIndex);
            if (record) {
                processText(text, info, infoType);
            }
        }

        if (isLabel && rightIndex + 1 < processedLine.length()
            && rightIndex > 0) {
            processedLine = processedLine.subString(rightIndex + 1);
            rightIndex = 0;
        }
        else if (!isLabel && rightIndex < processedLine.length()
            && rightIndex > 0) {
            processedLine = processedLine.subString(rightIndex);
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
    bool & record) {
    
    LabelType type = determineLabelType(label);
    bool startPairLabel = false;
    switch (type) {
    case PAIR:
        startPairLabel = (label[0] != L'/');
        if (startPairLabel) {
            labelStack.push(label);
            if (!record) {
                infoType = parseStackTopLabel(label);
                if (infoType != NONE) {
                    record = true;
                }
            }           
        }
        else {
            while (!labelStack.empty()
                && !labelMatch(labelStack.top(), label)
                && !labelPriorer(labelStack.top(), label)) {

                InfoType info = parseStackTopLabel(labelStack.top());
                labelStack.pop();
                if (info != NONE) {
                    infoType = NONE;
                    record = false;
                }
            }
            if (!labelStack.empty()
                && labelMatch(labelStack.top(), label)) {
                InfoType info = parseStackTopLabel(labelStack.top());
                labelStack.pop();
                if (info != NONE) {
                    infoType = NONE;
                    record = false;
                }
            }
        }
        break;
    case SINGLE:
        break;
    case NOTATION:
        break;
    default:
        break;
    }
}

void processText(const CharString & text, 
    NewsInfo & info, 
    const InfoType & infoType) {
    
    switch (infoType) {
    case TITLE:
        info.setTitle(text);
        std::wcout << text << std::endl;
        break;
    case TIME_AND_SOURCE:
        info.appendTimeAndSource(text);
        std::wcout << text << std::endl;
        break;
    case CONTENT:
        info.appendContent(text);
        std::wcout << text;
        break;
    case NONE:
        break;
    default:
        break;
    }
}

InfoType parseStackTopLabel(const CharString & label) {
    CharString titlePattern;
    CharString timeAndSourcePattern;
    CharString contentPattern;

    titlePattern = L"h1";
    timeAndSourcePattern = L"post_time_source";
    contentPattern = L"id=\"endText\"";

    if (label.indexOf(titlePattern) != -1) {
        return TITLE;
    }
    else if (label.indexOf(timeAndSourcePattern) != -1) {
        return TIME_AND_SOURCE;
    }
    else if (label.indexOf(contentPattern) != -1) {
        return CONTENT;
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
