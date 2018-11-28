#include "CharString.h"

CharString::CharString() {
    maxSize = INIT_SIZE;
    items = new wchar_t[maxSize + 1];
    len = 0;
}

CharString::CharString(const CharString & cs) {
    len = cs.length();
    maxSize = len + INCREMENT;
    items = new wchar_t[maxSize + 1];
    for (int i = 0; i < len; i++) {
        items[i] = cs[i];
    }
    items[len] = L'\0';
}

CharString::~CharString() {
    delete[] items;
}

int CharString::indexOf(const wchar_t w) const {
    for (int i = 0; i < len; i++) {
        if (items[i] == w) {
            return i;
        }
    }
    return -1;
}

int CharString::indexOf(const CharString & cstr) const {
    // 这里应用了KMP算法
    int cLen = cstr.length();
    if (cLen > len) {
        return -1;
    }
    int i = 0;
    int j = 0;
    int * next = cstr.getNext();
    while (i < len && j < cLen) {
        if (j == -1 || items[i] == cstr[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }
    delete[] next;
    if (j >= cLen) {
        return i - cLen;
    }
    else {
        return -1;
    }
}

const int CharString::length() const {
    return len;
}

int * CharString::getNext() const {
    int * next = new int[len + 2];
    int j = 0;
    next[0] = -1;
    int k = -1;
    while (j < len) {
        if (k == -1 || items[j] == items[k]) {
            k++;
            j++;
            next[j] = k;
        }
        else {
            k = next[k];
        }
    }
    return next;
}

const std::wstring CharString::wstring() const {
    return std::wstring(items);
}

const wchar_t * CharString::wchar() const {
    return items;
}

CharString CharString::trim() {
    CharString cs;
    if (len > 0) {
        int leftIndex = 0;
        int rightIndex = len;
        // 分别从首尾开始遍历，去掉空白字符直到找到非空白的字符
        for (int i = 0; i < len - 1; i++) {
            if (items[i] != L' ' && items[i] != L'\t') {
                leftIndex = i;
                break;
            }
        }
        for (int i = len - 1; i > 0; i--) {
            if (items[i] != L' ' && items[i] != L'\t') {
                rightIndex = i + 1;
                break;
            }
        }
        cs = this->subString(leftIndex, rightIndex);
    }
    else {
        cs = L"";
    }
    return cs;
}

bool CharString::blank() const {
    for (int i = 0; i < len; i++) {
        if (items[i] != L' '
            && items[i] != L'\t') {
            return false;
        }
    }
    return true;
}

CharString CharString::subString(const int startPos, const int endPos) const {
    if (startPos < 0 || endPos > len) { // 参数合法性检验
        throw ERROR;
    }
    if (startPos >= endPos) { // 参数合法性检验
        throw ERROR;
    }
    int newLen = endPos - startPos;
    CharString sub;
    for (int i = 0; i < newLen; i++) {
        sub.concat(items[startPos + i]);
    }
    return sub;
}

CharString CharString::subString(const int startPos) const {
    return subString(startPos, len);
}

void CharString::concat(const CharString & cstr) {
    int cstrLen = cstr.length();
    int newSize = maxSize;
    if (cstrLen + len >= newSize - 1) { // 拼接后长度超出当前分配的空间
        while (cstrLen + len >= newSize) {
            newSize += INCREMENT;
        }
        wchar_t * newItems = new wchar_t[newSize + 1];
        for (int i = 0; i < len; i++) {
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
    }
    for (int i = 0; i < cstrLen; i++) {
        items[i + len] = cstr[i];
    }
    len += cstrLen;
    items[len] = L'\0';
}

void CharString::concat(const wchar_t w) {
    if (len == maxSize - 1) { // 拼接后长度超出当前分配的空间
        maxSize += INCREMENT;
        wchar_t * newItems = new wchar_t[maxSize + 1];
        for (int i = 0; i < len; i++) {
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
    }
    items[len] = w;
    len++;
    items[len] = L'\0';
}

void CharString::operator=(const CharString & cstr) {
    int cLen = cstr.length();
    if (cLen) { // cstr为非空字符串
        maxSize = cLen + INCREMENT;
        delete[] items;
        items = new wchar_t[maxSize + 1];
        len = cLen;

        for (int i = 0; i < cLen; i++) {
            items[i] = cstr[i];
        }
        items[len] = L'\0';
    }
    else { // cstr为空字符串
        len = 0;
        maxSize = INIT_SIZE;
        delete[] items;
        items = new wchar_t[maxSize + 1];
        items[0] = L'\0';
    }
}

void CharString::operator=(const std::wstring & wstr) {
    int sLen = wstr.length();
    if (sLen) { // wstr为非空字符串
        maxSize = sLen + INCREMENT;
        delete[] items;
        items = new wchar_t[maxSize + 1];
        len = sLen;

        for (int i = 0; i < len; i++) {
            items[i] = wstr[i];
        }
        items[len] = L'\0';
    }
    else { // wstr为空字符串
        len = 0;
        maxSize = INIT_SIZE;
        delete[] items;
        items = new wchar_t[maxSize + 1];
        items[0] = L'\0';
    }
}

wchar_t & CharString::operator[](const int index) {
    if (index >= len
        || index < 0) { // 访问越界
        throw ERROR;
    }
    return items[index];
}

wchar_t & CharString::operator[](const int index) const {
    if (index >= len
        || index < 0) { // 访问越界
        throw ERROR;
    }
    return items[index];
}

std::wostream & operator<<(std::wostream & out, const CharString & cs) {
    // 设置代码页936
    std::locale loc(".936");
    out.imbue(loc);
    for (int i = 0; i < cs.length(); i++) {
        out << cs[i];
    }
    return out;
}

std::wifstream & operator>>(std::wifstream & in, CharString & cs) {
    // 设置代码页936
    std::locale loc(".936");
    in.imbue(loc);
    std::wstring wstr;
    in >> wstr;
    cs = wstr;
    return in;
}

bool operator==(const CharString & cs1, const CharString & cs2) {
    int len1 = cs1.length();
    int len2 = cs2.length();
    if (len1 != len2) {
        return false;
    }
    for (int i = 0; i < len1; i++) {
        if (cs1[i] != cs2[i]) {
            return false;
        }
    }
    return true;
}
