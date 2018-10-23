#include "NewsInfo.h"

NewsInfo::NewsInfo() {
}

NewsInfo::~NewsInfo() {
}

void NewsInfo::setTitle(const CharString & title) {
    this->title = title;
}

void NewsInfo::appendTimeAndSource(const CharString & timeAndSource) {
    this->timeAndSource.concat(timeAndSource);
}

void NewsInfo::appendContent(const CharString & content) {
    this->content.concat(content);
}

const CharString & NewsInfo::getTitle() const {
    return title;
}

const CharString & NewsInfo::getSource() const {
    return source;
}

const CharString & NewsInfo::getTime() const {
    return time;
}

const CharString & NewsInfo::getContent() const {
    return content;
}
