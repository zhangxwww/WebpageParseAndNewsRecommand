#ifndef NEWS_INFO_H
#define NEWS_INFO_H

#include "CharString.h"

class NewsInfo {
public:
    NewsInfo();
    ~NewsInfo();

    void setTitle(const CharString & title);
    void appendTimeAndSource(const CharString & timeAndSource);
    void appendContent(const CharString & content);

    void divideTimeAndSource();
    void postProcess();

    const CharString & getTitle() const;
    const CharString & getSource() const;
    const CharString & getTime() const;
    const CharString & getContent() const;

private:
    CharString title;
    CharString timeAndSource;
    CharString source;
    CharString time;
    CharString content;
};

#endif // !NEWS_INFO_H
