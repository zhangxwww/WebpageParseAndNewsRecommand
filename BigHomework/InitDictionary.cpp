#include "InitDictionary.h"

CharStringHashTable initDictionary() {
    CharString dictionaryPath;
    dictionaryPath = L".\\dict\\´Ê¿â.dic";
    std::wifstream dictionary(dictionaryPath.wstring());
    std::locale loc(".936");
    dictionary.imbue(loc);

    CharStringHashTable hashTable;

    CharString word;
    int count = 0;

    std::cout << "Start to init dictionary ..." << std::endl;

    while (dictionary >> word) {
        hashTable.add(word);
        count++;
        if (count % 10000 == 0) {
            std::cout << count << std::endl;
        }
    }
    dictionary.close();

    std::cout << "Finish init!" << std::endl;
    std::cout << std::endl;

    return hashTable;
}