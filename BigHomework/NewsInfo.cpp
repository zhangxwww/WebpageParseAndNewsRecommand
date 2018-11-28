#include "NewsInfo.h"

NewsInfo::NewsInfo() {
}

void NewsInfo::setTitle(const CharString & title) {
    this->title = title;
}

void NewsInfo::appendTimeAndSource(const CharString & timeAndSource) {
    this->timeAndSource.concat(timeAndSource);
}

void NewsInfo::appendContent(const CharString & content) {
    if (!content.blank()) {
        this->content.concat(content);
    }    
}

void NewsInfo::divideTimeAndSource() {
    CharString pattern;
    pattern = L"À´Ô´";

    int divisionIndex = timeAndSource.indexOf(pattern);
    if (divisionIndex > 0) {
        time = timeAndSource.subString(0, divisionIndex).trim();
        source = timeAndSource.subString(divisionIndex + 3).trim();
    }
    else {
        time = timeAndSource.trim();
        source = L"";
    }
}

void NewsInfo::postProcess() {
    divideTimeAndSource();
    title = title.trim();
    time = time.trim();
    source = source.trim();
    if (content.length() == 0) {
        return;
    }
    content = content.trim();
    if (content[0] == L'\n') {
        content = content.subString(1);
    }
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
