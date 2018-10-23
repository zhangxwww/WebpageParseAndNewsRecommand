#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "NewsInfo.h"
#include "Stack.h"
#include "LabelType.h"
#include "InfoType.h"

void extractInfo();

/*************************Assisted functions*************************/

Stack<CharString> getHTMLList();

const NewsInfo parseOneNewsPage(const CharString & HTMLfilename);

void parseLine(const CharString & line,
    NewsInfo & info,
    Stack<CharString> & labelStack,
    InfoType & infoType,
    bool & record);

LabelType determineLabelType(const CharString & label);

void processLabel(const CharString & label,
    Stack<CharString> & labelStack,
    InfoType & infoType,
    bool & record);

void processText(const CharString & text,
    NewsInfo & info,
    const InfoType & infoType);

InfoType parseStackTopLabel(const CharString & label);

bool labelMatch(const CharString & startLabel,
    const CharString & endLabel);

bool labelPriorer(const CharString & stackTopLabel,
    const CharString & currentLabel);

void saveNewsInfo(const NewsInfo & newsInfo,
    const CharString & HTMLfilename);

#endif // !ALGORITHM_H
