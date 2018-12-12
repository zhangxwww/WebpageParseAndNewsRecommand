#include "Recommend.h"
#include "Query.h"
#include "DocIdToTitle.h"
#include "DivideWords.h"
#include "BuildInvertedFiles.h"
#include "CharStringLink.h"
#include "CharStringLinkNode.h"
#include "InvertedFileLinkList.h"
#include "InvertedFileLinkNode.h"

void recommendAll(CharString * map,
 
    BalancedBinaryTree * tree, CharStringHashTable * dictionary) {

    std::cout << "Start to recommend" << std::endl;

    CharString queryFileName;
    CharString resultFileName;
    queryFileName = L"query2.txt";
    resultFileName = L"result2.txt";
    std::wifstream queryFile(queryFileName.wstring());
    std::wofstream resultFile(resultFileName.wstring());
    std::locale loc(".936");
    queryFile.imbue(loc);
    resultFile.imbue(loc);

    std::wstring line;
    CharString title;

    // ÿ�ζ����һ�У�����һ���Ƽ�
    while (!queryFile.eof()) {
        std::getline(queryFile, line);
        title = line;

        CharStringLink * recommendResults 
            = recommend(map, title, tree, dictionary);      
        saveRecommendResults(map, recommendResults, resultFile);

        line.clear();
        if (recommendResults != nullptr) {
            delete recommendResults;
        }
    }
    queryFile.close();
    resultFile.close();
    std::cout << "Finish recommending!" << std::endl;
    std::cout << std::endl;
}

CharStringLink * recommend(CharString * map,
 
    const CharString & title,
 
    BalancedBinaryTree * tree, CharStringHashTable * dictionary) {
   
    // ��ñ����Ӧ��id
    int id = searchDocIdByTitle(map, title);
    if (id == -1) {
        return nullptr;
    }
    CharStringLink * result = new CharStringLink;
    CharStringLink * wordsInFile = new CharStringLink;
    // �Ӷ�Ӧ�ķִ��ļ��ж�������ѯ�ı����Ӧ�����µķִʽ��
    fromTxtFile(id, wordsInFile);
    CharStringLink queryWords = divideOneLine(*dictionary, title);
    queryWords.append(*wordsInFile);
    queryWords.clearShorterThan(2);
    queryWords.clearNumbers();
    // TODO slice 20 words
    // ��ѯ����õ������еĴ�
    InvertedFileLinkList * fileList = query(tree, &queryWords);
    // ȡ����ѯ�����ǰ5����Ϊ���ս��
    int count = 0;
    InvertedFileLinkNode * p = fileList->getHead()->getNext();
    while (p != nullptr && p->getID() != -1 && count < 5) {
        result->add(map[p->getID()]);
        p = p->getNext();
        count++;
    }
    if (fileList != nullptr) {
        delete fileList;
    }
    if (wordsInFile != nullptr) {
        delete wordsInFile;
    }
    return result;
}

void saveRecommendResults(CharString * map, 
    CharStringLink * recommendDocs, 
    std::wofstream & file) {

    if (recommendDocs == nullptr) {
        file << L"�����Ų������ݿ��У��޷��Ƽ� :)";
    }
    else {
        CharStringLinkNode * p;
        while (recommendDocs->length() > 0) {
            p = recommendDocs->pop();
            CharString title = p->getCharString();
            file << generateRecommendResultWithCorrectFormat(
                searchDocIdByTitle(map, title), title);
        }
    }
    file << std::endl;
}

const CharString generateRecommendResultWithCorrectFormat(const int id, const CharString & title) {
    
    CharString result;
    result = L"(";
    result.concat(CharString::parseFromInteger(id));
    result.concat(L',');
    result.concat(title);
    result.concat(L')');
    result.concat(L' ');
    return result;
}
