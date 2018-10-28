#ifndef EXTRACT_INFO_H
#define EXTRACT_INFO_H

#include "NewsInfo.h"
#include "Stack.h"
#include "LabelType.h"
#include "InfoType.h"

/**
 *  分析提取某一个网页的信息
 *  @param HTMLfilename: 所要提取的网页的文件名
 *  @return            : 从这一网页中所提取出的信息
 */
const NewsInfo extractInfo(const CharString & HTMLfilename);


/*********************Assisted functions*********************/

/**
 *  获取input文件夹下所有的.html文件的文件名
 *  @return: CharString类型的栈，保存所获取的所有文件名
 */
Stack<CharString> getHTMLList();


/**
 *  提取所有的网页信息，将结果保存在对应的.info文件中
 */
void extractInfoInAllPages();


/**
 *  分析某一行html代码的内容，对相应的状态进行调整
 *  @param line        : 所要分析的代码行
 *  @param info        : 该网页对应的信息
 *  @param labelStack  : 用于遍历网页标签所用的栈
 *  @param infoType    : html标签所对应的类型，用于确定信息的类型
 *  @param record      : 是否记录文本内容
 *  @param newParagraph: 是否换行
 *  @param endOf       : 是否结束该网页的读取
 *  @param skip        : 是否应该跳过某一段文本
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
 *  确定某一标签的类型
 *  @param label: 所要处理的标签
 *  @return     : 标签的类型
 */
LabelType determineLabelType(const CharString & label);


/**
 *  处理标签，对相应的状态进行改变
 *  @param label       : 标签名
 *  @param labelStack  : 用于遍历全部标签所用的栈
 *  @param infoType    : 标签所对应的信息类型
 *  @param record      : 是否记录文本内容
 *  @param newParagraph: 是否换行
 *  @param skip        : 是否跳过某一段文本
 */
void processLabel(const CharString & label,
    Stack<CharString> & labelStack,
    InfoType & infoType,
    bool & record,
    bool & newParagraph, 
    bool & skip);


/**
 *  根据相应的各种状态处理文本，并改变对应状态
 *  @param text        : 文本
 *  @param info        : 提取出来的该网页的信息
 *  @param infoType    : 标签所对应的信息类型
 *  @param newParagraph: 是否换行
 *  @param endOf       : 是否结束该网页的读取
 */
void processText(CharString & text,
    NewsInfo & info,
    const InfoType & infoType,
    bool & newParagraph,
    bool & endOf);


/**
 *  过滤一段文本，去除html字符实体等，以及某些无关语句
 *  @param text : 需要过滤的文本
 *  @param endOf: 是否结束该网页的读取
 *  @return     : 如果文本中不含某些特殊的语句则返回true，否则返回false
 */
bool filtText(CharString & text, bool & endOf);


/**
 *  处理栈顶标签
 *  @param text : 栈顶标签
 *  @return     : 标签所对应的信息类型
 */
InfoType parseStackTopLabel(const CharString & label);


/**
 *  判断开始标签是否与结束标签匹配
 *  @param startLabel : 开始标签
 *  @param endLabel   : 结束标签
 *  @return           : 匹配则返回true，否则返回false
 */
bool labelMatch(const CharString & startLabel,
    const CharString & endLabel);


/**
 *  判断当前标签与栈顶标签的优先级
 *  @param stackTopLabel: 栈顶标签
 *  @param currentLabel : 当前标签
 *  @return             : 栈顶标签优先级高则返回true，否则返回false
 */
bool labelPriorer(const CharString & stackTopLabel,
    const CharString & currentLabel);


/**
 *  将所提取的信息保存在对应的.info文件中
 *  @param newsInfo    : 提取到的信息
 *  @param HTMLfilename: .html文件的文件名
 */
void saveNewsInfo(const NewsInfo & newsInfo,
    const CharString & HTMLfilename);

#endif // !EXTRACT_INFO_H
