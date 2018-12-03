#include "DivideWords.h"

#include <io.h>
#include <fstream>

CharStringLink divideWords(
    const CharString & infoFilename,
    const CharStringHashTable & hashTable) {

    CharString filePath;
    filePath = L".\\output\\";
    filePath.concat(infoFilename);

    std::wifstream infoFile(filePath.wstring());
    std::locale loc(".936");
    infoFile.imbue(loc);

    std::wstring line;
    CharString csLine;

    CharStringLink dividedWords;

    std::getline(infoFile, line); // title
    std::getline(infoFile, line); // source
    std::getline(infoFile, line); // time

    while (!infoFile.eof()) {
        // һ��һ�ж�������
        std::getline(infoFile, line);
        if (line.empty()) {
            continue;
        }
        csLine = line;
        // ��ÿһ�еķִʽ��append�����еĽ��֮��
        dividedWords.append(divideOneLine(hashTable, csLine));
    }
    // ���ִʽ������Ϊtxt
    saveDividedWords(dividedWords, infoFilename);
    return dividedWords;
}

void divideWordsInAllFiles(const CharStringHashTable & hashTable) {

    Stack<CharString> infoFileList = getInfoFileList();

    std::cout << "Dividing ..." << std::endl;

    while (!infoFileList.empty()) {
        // �ֱ��ÿһ��.info�ļ����зִʲ���
        CharString infoFilename = infoFileList.top();
        std::wcout << infoFilename << std::endl;
        CharStringLink divideResults = divideWords(infoFilename, hashTable);
        infoFileList.pop();
    }

    std::cout << "Finish dividing!" << std::endl;
    std::cout << std::endl;
}

Stack<CharString> getInfoFileList() {
    Stack<CharString> infoFileList;
    CharString path;
    path = L".\\output\\*.info";

    intptr_t hFile = 0;
    struct _wfinddata_t fileData;
    const wchar_t * dirPath = path.wchar();
    if ((hFile = _wfindfirst(dirPath, &fileData)) != -1) {
        do {
            CharString infoFilename;
            infoFilename = fileData.name;
            infoFileList.push(infoFilename);
        } while (_wfindnext(hFile, &fileData) == 0);
        _findclose(hFile);
    }
    return infoFileList;
}

const CharStringLink divideOneLine(
    const CharStringHashTable & hashTable, 
    const CharString & line) {
  
    int len = line.length();
    CharStringLink dividedLine;
    for (int start = 0; start < len; start++) {
        // ��ȡ��һ��ƥ��Ĵʻ򵥸��֣�����start����ƶ���Ӧ�ľ���
        CharString word = getNextWord(line, start, hashTable);
        if (word.length() == 0) {
            continue;
        }
        dividedLine.add(word);
        start += word.length() - 1;
    } 
    return dividedLine;
}

const CharString getNextWord(
    const CharString & line,
    int start, 
    const CharStringHashTable & hashTable) {

    const int len = line.length();
    // �ʿ�����Ĵ�Ϊ17���ַ�
    const int WORD_MAX_LENGTH = 17;

    bool match = false;
    CharString potentialWord;
    // ��ȡ���ƥ��ԭ��
    for (int wordLen = WORD_MAX_LENGTH; wordLen > 1; wordLen--) {    
        if (start + wordLen > len) {
            potentialWord = line.subString(start);
        }
        else {
            potentialWord = line.subString(start, start + wordLen);
        }
        // �ô���ʿ��еĴ�ƥ�䣬��������һ��Ӣ�ĵ��ʣ�������һ������
        if (hashTable.find(potentialWord)
            || isEnglishWords(potentialWord)
            || isNumbers(potentialWord)) {
            match = true;
            break;
        }
    }
    // ���δƥ�䣬������Ϊһ����
    if (!match) {
        potentialWord = line.subString(start, start + 1);
    }
    // ���ֻ��һ���֣��ҼȲ������ġ�Ӣ�ģ�Ҳ�������֣�������Ϊһ�����ַ�
    if (potentialWord.length() == 1) {
        if (!isChineseCharacter(potentialWord)
            && !isEnglishWords(potentialWord)
            && !isNumbers(potentialWord)) {
            potentialWord = L"";
        }
    }
    return potentialWord;
}

bool isChineseCharacter(const CharString & cs) {

    // 0x4e00��0x9fa5��unicode�����к��ֵķ�Χ
    if (cs[0] >= 0x4e00 && cs[0] <= 0x9fa5) {
        return true;
    }
    return false;
}

bool isEnglishWords(const CharString & word) {
    int len = word.length();
    for (int i = 0; i < len; i++) {
        if ((word[i] < L'A' || word[i] > L'Z')
            && (word[i] < L'a' || word[i] > L'z')) {
            return false;
        }
    }
    return true;
}

bool isNumbers(const CharString & cs) {
    int len = cs.length();
    for (int i = 0; i < len; i++) {
        if (cs[i] < L'0' || cs[i] > L'9') {
            return false;
        }
    }
    return true;
}


void saveDividedWords(
    const CharStringLink & dividedWords, 
    const CharString & infoFilename) {

    CharString filePath;
    filePath = L".\\output\\";
    CharString postfix;
    postfix = L".txt";
    CharString infoFilePostfix;
    infoFilePostfix = L".info";

    filePath.concat(infoFilename.
        subString(0, infoFilename.indexOf(infoFilePostfix)));
    filePath.concat(postfix);

    std::wofstream txtFile(filePath.wstring());
    std::locale loc(".936");
    txtFile.imbue(loc);

    txtFile << dividedWords << std::endl;
    txtFile.close();
}
