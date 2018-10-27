#ifndef DIVIDE_WORDS_H
#define DIVIDE_WORDS_H

#include "CharStringLink.h"
#include "Stack.h"
#include "CharStringHashTable.h"

const CharStringLink divideWords(
    const CharStringHashTable & hashTable);

/*********************Assisted functions*********************/

Stack<CharString> getInfoFileList();

const CharStringLink divideWordInOneInfoFile(
    const CharString & infoFilename,
    const CharStringHashTable & hashTable);

const CharStringLink divideOneLine(
    const CharStringHashTable & hashTable, 
    const CharString & line);

const CharString getNextWord(
    const CharString & line,
    int start, 
    const CharStringHashTable & hashTable);

bool isChineseCharacter(const CharString & cs);

void saveDividedWords(
    const CharStringLink & dividedWords,
    const CharString & infoFilename);

#endif // !DIVIDE_WORDS_H
