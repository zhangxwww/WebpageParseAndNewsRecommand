#include "BuildInvertedFiles.h"
#include "BalancedBinaryTree.h"
#include "InvertedFileLinkList.h"
#include "ExtractInfo.h"
#include "InitDictionary.h"
#include "DivideWords.h"

BalancedBinaryTree * buildInvertedFiles() {

    BalancedBinaryTree * tree = new BalancedBinaryTree;

    // 这里的hash table是用于分词的
    CharStringHashTable hashTable;
    bool hashTableInited = false;
   
    for (int i = 0; i < BIF::COUNT_FILES; i++) {
        CharStringLink * words = new CharStringLink;
        // .\output目录下不存在对应的分词文件.txt
        if (!fromTxtFile(i, words)) {
            if (!hashTableInited) {
                hashTable = initDictionary();
                hashTableInited = true;
            }
            // .\output目录下不存在对应的信息文件.info
            if (!fromInfoFile(i, words, &hashTable)) {
                // .\input目录下不存在对应的网页文件.html
                if (!fromHtmlFile(i, words, &hashTable)) {
                    std::wcout << L"不存在" << i << ".html" << L"文件" << std::endl;
                    continue;
                }
            }
        }
        words->clearShorterThan(2);
    }
    return tree;
}

bool fromTxtFile(const int order, 
    CharStringLink * words) {

    CharString txtFileName;
    CharString postFix;
    postFix = L".txt";
    txtFileName = L".\\output\\";
    txtFileName.concat(CharString::parseFromInteger(order));
    txtFileName.concat(postFix);
    std::wifstream file;
    std::locale loc(".936");
    file.imbue(loc);
    file.open(txtFileName.wstring(), std::ios::in);
    if (file) {
        file >> (*words);
    }
    else {
        return false;
    }
    return true;
}

bool fromInfoFile(const int order, 
    CharStringLink * words, 
    CharStringHashTable * hashTable) {

    CharString infoFileName;
    CharString postFix;
    postFix = L".info";
    infoFileName = L".\\output\\";
    infoFileName.concat(CharString::parseFromInteger(order));
    infoFileName.concat(postFix);
    std::wifstream file;
    std::locale loc(".936");
    file.imbue(loc);
    file.open(infoFileName.wstring(), std::ios::in);
    if (file) {
        (*words) = divideWords(infoFileName.subString(9), *hashTable);
    }
    else {
        return false;
    }
    return true;
}

bool fromHtmlFile(const int order, 
    CharStringLink * words, 
    CharStringHashTable * hashTable) {

    CharString htmlFileName;
    CharString postFixInfo;
    CharString postFixHtml;
    CharString path;
    path = L".\\input\\";
    postFixInfo = L".info";
    postFixHtml = L".html";
    htmlFileName = path;
    htmlFileName.concat(CharString::parseFromInteger(order));
    htmlFileName.concat(postFixHtml);

    std::wifstream file;
    std::locale loc(".936");
    file.imbue(loc);
    file.open(htmlFileName.wstring(), std::ios::in);
    if (file) {
        const NewsInfo info = extractInfo(htmlFileName.subString(8));
        (*words) = divideOneLine(*hashTable, info.getContent());
    }
    else {
        return false;
    }
    return true;
}
