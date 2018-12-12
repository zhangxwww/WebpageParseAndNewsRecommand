#include "DocIdToTitle.h"
#include "CharString.h"
#include "WebPagesInfo.h"

#include <fstream>
#include <string>

CharString * getDocIdToTitle() {
    CharString * map = new CharString[781];

    CharString path;
    path = L".\\output\\";
    CharString postFix;
    postFix = L".info";
    CharString fileName;

    std::wifstream infoFile;
    std::locale loc(".936");
    infoFile.imbue(loc);

    std::wstring line;

    for (int id = 0; id < WPI::COUNT_FILES; id++) {
        fileName = path;
        fileName.concat(CharString::parseFromInteger(id));
        fileName.concat(postFix);
        infoFile.open(fileName.wstring());
        if (infoFile) {
            std::getline(infoFile, line);
            map[id] = line;
            infoFile.close();
        }
        else {
            map[id] = L"";
        }
        line.clear();
    }
    return map;
}

int searchDocIdByTitle(CharString * map, 
    const CharString & title) {

    if (title.blank()) {
        return -1;
    }
    for (int i = 0; i < WPI::COUNT_FILES; i++) {
        if (title == map[i]) {
            return i;
        }
    }
    return -1;
}
