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

    // 每次读入的一行，就是一次推荐
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
   
    // 获得标题对应的id
    int id = searchDocIdByTitle(map, title);
    if (id == -1) {
        return nullptr;
    }
    CharStringLink * result = new CharStringLink;
    CharStringLink * wordsInFile = new CharStringLink;
    // 从对应的分词文件中读出所查询的标题对应的文章的分词结果
    fromTxtFile(id, wordsInFile);
    CharStringLink queryWords = divideOneLine(*dictionary, title);
    queryWords.append(*wordsInFile);
    queryWords.clearShorterThan(2);
    queryWords.clearNumbers();
    // TODO slice 20 words
    // 查询上面得到的所有的词
    InvertedFileLinkList * fileList = query(tree, &queryWords);
    // 取出查询结果的前5个作为最终结果
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
        file << L"该新闻不再数据库中，无法推荐 :)";
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
