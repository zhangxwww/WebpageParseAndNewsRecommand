#ifndef EXTRACT_INFO_H
#define EXTRACT_INFO_H

#include "NewsInfo.h"
#include "Stack.h"
#include "LabelType.h"
#include "InfoType.h"

void extractInfo();

/*********************Assisted functions*********************/

Stack<CharString> getHTMLList();

const NewsInfo parseOneNewsPage(const CharString & HTMLfilename);

void parseLine(const CharString & line,
    NewsInfo & info,
    Stack<CharString> & labelStack,
    InfoType & infoType,
    bool & record,
    bool & newParagraph,
    bool & endOf);

LabelType determineLabelType(const CharString & label);

void processLabel(const CharString & label,
    Stack<CharString> & labelStack,
    InfoType & infoType,
    bool & record,
    bool & newParagraph);

void processText(CharString & text,
    NewsInfo & info,
    const InfoType & infoType,
    bool & newParagraph,
    bool & endOf);

bool filtText(CharString & text, bool & endOf);

InfoType parseStackTopLabel(const CharString & label);

bool labelMatch(const CharString & startLabel,
    const CharString & endLabel);

bool labelPriorer(const CharString & stackTopLabel,
    const CharString & currentLabel);

void saveNewsInfo(const NewsInfo & newsInfo,
    const CharString & HTMLfilename);

#endif // !EXTRACT_INFO_H
