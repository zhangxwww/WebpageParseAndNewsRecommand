#ifndef NEWS_INFO_H
#define NEWS_INFO_H

#include "CharString.h"

/**
 * �����Զ����������Ϣ�࣬����ĳһ��ҳ����ȡ���ĸ�����Ϣ
 */
class NewsInfo {
public:
    NewsInfo();

    /**
     *  ���ñ���
     *  @param title: ���ű���
     */
    void setTitle(const CharString & title);


    /**
     *  ����ʱ�����Դ
     *  @param timeAndSource: ����ʱ�����Դ
     */
    void appendTimeAndSource(const CharString & timeAndSource);


    /**
     *  �������
     *  @param content: ��һ������������
     */
    void appendContent(const CharString & content);


    /**
     *  ��ȡ����
     *  @return: ���ű���
     */
    const CharString & getTitle() const;


    /**
     *  ��ȡ��Դ
     *  @return: ������Դ
     */
    const CharString & getSource() const;


    /**
     *  ��ȡʱ��
     *  @return: ����ʱ��
     */
    const CharString & getTime() const;


    /**
     *  ��ȡ����
     *  @return: ��������
     */
    const CharString & getContent() const;


    /**
     *  ����ʱ������Դ
     */
    void divideTimeAndSource();


    /**
     *  ���Ĵ�����ȥ����Ŀհ��ַ�
     */
    void postProcess();

private:
    /* ���ű��� */
    CharString title;

    /* ����ʱ������Դ */
    CharString timeAndSource;

    /* ������Դ */
    CharString source;

    /* ����ʱ�� */
    CharString time;

    /* �������� */
    CharString content;
};

#endif // !NEWS_INFO_H
