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
        // 一行一行读入正文
        std::getline(infoFile, line);
        if (line.empty()) {
            continue;
        }
        csLine = line;
        // 将每一行的分词结果append在已有的结果之后
        dividedWords.append(divideOneLine(hashTable, csLine));
    }
    // 将分词结果保存为txt
    saveDividedWords(dividedWords, infoFilename);
    return dividedWords;
}

void divideWordsInAllFiles(const CharStringHashTable & hashTable) {

    Stack<CharString> infoFileList = getInfoFileList();

    std::cout << "Dividing ..." << std::endl;

    while (!infoFileList.empty()) {
        // 分别对每一个.info文件进行分词操作
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
        // 获取下一个匹配的词或单个字，并将start向后移动相应的距离
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
    // 词库里最长的词为17个字符
    const int WORD_MAX_LENGTH = 17;

    bool match = false;
    CharString potentialWord;
    // 采取最大匹配原则
    for (int wordLen = WORD_MAX_LENGTH; wordLen > 1; wordLen--) {    
        if (start + wordLen > len) {
            potentialWord = line.subString(start);
        }
        else {
            potentialWord = line.subString(start, start + wordLen);
        }
        // 该词与词库中的词匹配，或者这是一个英文单词，或者是一串数字
        if (hashTable.find(potentialWord)
            || isEnglishWords(potentialWord)
            || isNumbers(potentialWord)) {
            match = true;
            break;
        }
    }
    // 如果未匹配，则设置为一个字
    if (!match) {
        potentialWord = line.subString(start, start + 1);
    }
    // 如果只有一个字，且既不是中文、英文，也不是数字，则设置为一个空字符
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

    // 0x4e00与0x9fa5是unicode编码中汉字的范围
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
