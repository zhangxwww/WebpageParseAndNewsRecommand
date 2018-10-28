#ifndef DIVIDE_WORDS_H
#define DIVIDE_WORDS_H

#include "CharString.h"
#include "CharStringLink.h"
#include "Stack.h"
#include "CharStringHashTable.h"


const CharStringLink divideWords(
    const CharString & infoFilename,
    const CharStringHashTable & hashTable);

/*********************Assisted functions*********************/

void divideWordsInAllFiles(
    const CharStringHashTable & hashTable);

Stack<CharString> getInfoFileList();

const CharStringLink divideOneLine(
    const CharStringHashTable & hashTable, 
    const CharString & line);

const CharString getNextWord(
    const CharString & line,
    int start, 
    const CharStringHashTable & hashTable);

bool isChineseCharacter(const CharString & cs);

bool isEnglishWords(const CharString & words);

bool isNumbers(const CharString & cs);

void saveDividedWords(
    const CharStringLink & dividedWords,
    const CharString & infoFilename);

#endif // !DIVIDE_WORDS_H
