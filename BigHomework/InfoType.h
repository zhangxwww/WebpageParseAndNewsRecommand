#ifndef INFO_TYPE_H
#define INFO_TYPE_H

/**
 * 该枚举表示从标签中提取出来的信息类型
 */
enum InfoType {
    /* 默认为NONE */
    NONE,

    /* 网页标题 */
    TITLE,

    /* 时间和来源 */
    TIME_AND_SOURCE,

    /* 正文 */
    CONTENT,

    /* 新的段落 */
    NEW_PARAGRAPH,

    /* 跳过某段文本 */
    SKIP
};

#endif // !INFO_TYPE_H
