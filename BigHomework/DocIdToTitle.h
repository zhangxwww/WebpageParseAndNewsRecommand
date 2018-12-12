#ifndef DOC_ID_TO_TITLE
#define DOC_ID_TO_TITLE

class CharString;

/**
 *  获取文档id与其标题之间的映射
 *  @return: 字符串数组，索引为id，值为标题
 */
CharString * getDocIdToTitle();


/**
 *  通过标题搜索文章id
 *  @param map  : id与标题之间的映射
 *  @param title: 标题
 *  @return     : 标题对应id，标题为空或不存在对应id则返回-1
 */
int searchDocIdByTitle(CharString * map, 
    const CharString & title);

#endif // !DOC_ID_TO_TITLE
