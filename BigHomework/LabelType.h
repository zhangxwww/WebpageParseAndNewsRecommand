#ifndef LABEL_TYPE_H
#define LABEL_TYPE_H

/**
 * 该枚举表示标签的类型
 */
enum LabelType {
    /* 表示不会成对出现的标签 */
    SINGLE,

    /* 表示成对出现的标签 */
    PAIR,

    /* 表示注释等无关信息的标签 */
    NOTATION
};

#endif // !LABEL_TYPE
