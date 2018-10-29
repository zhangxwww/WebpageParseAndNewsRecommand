#ifndef NEWS_INFO_H
#define NEWS_INFO_H

#include "CharString.h"

/**
 * 这是自定义的新闻信息类，保存某一网页中提取出的各种信息
 */
class NewsInfo {
public:
    NewsInfo();

    /**
     *  设置标题
     *  @param title: 新闻标题
     */
    void setTitle(const CharString & title);


    /**
     *  设置时间和来源
     *  @param timeAndSource: 新闻时间和来源
     */
    void appendTimeAndSource(const CharString & timeAndSource);


    /**
     *  添加正文
     *  @param content: 下一部分新闻正文
     */
    void appendContent(const CharString & content);


    /**
     *  获取标题
     *  @return: 新闻标题
     */
    const CharString & getTitle() const;


    /**
     *  获取来源
     *  @return: 新闻来源
     */
    const CharString & getSource() const;


    /**
     *  获取时间
     *  @return: 新闻时间
     */
    const CharString & getTime() const;


    /**
     *  获取正文
     *  @return: 新闻正文
     */
    const CharString & getContent() const;


    /**
     *  分离时间与来源
     */
    void divideTimeAndSource();


    /**
     *  最后的处理，除去多余的空白字符
     */
    void postProcess();

private:
    /* 新闻标题 */
    CharString title;

    /* 新闻时间与来源 */
    CharString timeAndSource;

    /* 新闻来源 */
    CharString source;

    /* 新闻时间 */
    CharString time;

    /* 新闻正文 */
    CharString content;
};

#endif // !NEWS_INFO_H
