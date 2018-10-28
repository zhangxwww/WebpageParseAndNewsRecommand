#ifndef EXTRACT_INFO_H
#define EXTRACT_INFO_H

#include "NewsInfo.h"
#include "Stack.h"
#include "LabelType.h"
#include "InfoType.h"

/**
 *  ������ȡĳһ����ҳ����Ϣ
 *  @param HTMLfilename: ��Ҫ��ȡ����ҳ���ļ���
 *  @return            : ����һ��ҳ������ȡ������Ϣ
 */
const NewsInfo extractInfo(const CharString & HTMLfilename);


/*********************Assisted functions*********************/

/**
 *  ��ȡinput�ļ��������е�.html�ļ����ļ���
 *  @return: CharString���͵�ջ����������ȡ�������ļ���
 */
Stack<CharString> getHTMLList();


/**
 *  ��ȡ���е���ҳ��Ϣ������������ڶ�Ӧ��.info�ļ���
 */
void extractInfoInAllPages();


/**
 *  ����ĳһ��html��������ݣ�����Ӧ��״̬���е���
 *  @param line        : ��Ҫ�����Ĵ�����
 *  @param info        : ����ҳ��Ӧ����Ϣ
 *  @param labelStack  : ���ڱ�����ҳ��ǩ���õ�ջ
 *  @param infoType    : html��ǩ����Ӧ�����ͣ�����ȷ����Ϣ������
 *  @param record      : �Ƿ��¼�ı�����
 *  @param newParagraph: �Ƿ���
 *  @param endOf       : �Ƿ��������ҳ�Ķ�ȡ
 *  @param skip        : �Ƿ�Ӧ������ĳһ���ı�
 */
void parseLine(const CharString & line,
    NewsInfo & info,
    Stack<CharString> & labelStack,
    InfoType & infoType,
    bool & record,
    bool & newParagraph,
    bool & endOf, 
    bool & skip);


/**
 *  ȷ��ĳһ��ǩ������
 *  @param label: ��Ҫ����ı�ǩ
 *  @return     : ��ǩ������
 */
LabelType determineLabelType(const CharString & label);


/**
 *  �����ǩ������Ӧ��״̬���иı�
 *  @param label       : ��ǩ��
 *  @param labelStack  : ���ڱ���ȫ����ǩ���õ�ջ
 *  @param infoType    : ��ǩ����Ӧ����Ϣ����
 *  @param record      : �Ƿ��¼�ı�����
 *  @param newParagraph: �Ƿ���
 *  @param skip        : �Ƿ�����ĳһ���ı�
 */
void processLabel(const CharString & label,
    Stack<CharString> & labelStack,
    InfoType & infoType,
    bool & record,
    bool & newParagraph, 
    bool & skip);


/**
 *  ������Ӧ�ĸ���״̬�����ı������ı��Ӧ״̬
 *  @param text        : �ı�
 *  @param info        : ��ȡ�����ĸ���ҳ����Ϣ
 *  @param infoType    : ��ǩ����Ӧ����Ϣ����
 *  @param newParagraph: �Ƿ���
 *  @param endOf       : �Ƿ��������ҳ�Ķ�ȡ
 */
void processText(CharString & text,
    NewsInfo & info,
    const InfoType & infoType,
    bool & newParagraph,
    bool & endOf);


/**
 *  ����һ���ı���ȥ��html�ַ�ʵ��ȣ��Լ�ĳЩ�޹����
 *  @param text : ��Ҫ���˵��ı�
 *  @param endOf: �Ƿ��������ҳ�Ķ�ȡ
 *  @return     : ����ı��в���ĳЩ���������򷵻�true�����򷵻�false
 */
bool filtText(CharString & text, bool & endOf);


/**
 *  ����ջ����ǩ
 *  @param text : ջ����ǩ
 *  @return     : ��ǩ����Ӧ����Ϣ����
 */
InfoType parseStackTopLabel(const CharString & label);


/**
 *  �жϿ�ʼ��ǩ�Ƿ��������ǩƥ��
 *  @param startLabel : ��ʼ��ǩ
 *  @param endLabel   : ������ǩ
 *  @return           : ƥ���򷵻�true�����򷵻�false
 */
bool labelMatch(const CharString & startLabel,
    const CharString & endLabel);


/**
 *  �жϵ�ǰ��ǩ��ջ����ǩ�����ȼ�
 *  @param stackTopLabel: ջ����ǩ
 *  @param currentLabel : ��ǰ��ǩ
 *  @return             : ջ����ǩ���ȼ����򷵻�true�����򷵻�false
 */
bool labelPriorer(const CharString & stackTopLabel,
    const CharString & currentLabel);


/**
 *  ������ȡ����Ϣ�����ڶ�Ӧ��.info�ļ���
 *  @param newsInfo    : ��ȡ������Ϣ
 *  @param HTMLfilename: .html�ļ����ļ���
 */
void saveNewsInfo(const NewsInfo & newsInfo,
    const CharString & HTMLfilename);

#endif // !EXTRACT_INFO_H
