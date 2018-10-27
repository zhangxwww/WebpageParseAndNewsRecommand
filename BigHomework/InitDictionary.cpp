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
    while (dictionary >> word) {
        hashTable.add(word);
        count++;
        if (count % 10000 == 0) {
            std::cout << count << std::endl;
        }
    }
    dictionary.close();

    return hashTable;
}