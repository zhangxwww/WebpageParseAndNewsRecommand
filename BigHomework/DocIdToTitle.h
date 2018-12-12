#ifndef DOC_ID_TO_TITLE
#define DOC_ID_TO_TITLE

class CharString;

/**
 *  ��ȡ�ĵ�id�������֮���ӳ��
 *  @return: �ַ������飬����Ϊid��ֵΪ����
 */
CharString * getDocIdToTitle();


/**
 *  ͨ��������������id
 *  @param map  : id�����֮���ӳ��
 *  @param title: ����
 *  @return     : �����Ӧid������Ϊ�ջ򲻴��ڶ�Ӧid�򷵻�-1
 */
int searchDocIdByTitle(CharString * map, 
    const CharString & title);

#endif // !DOC_ID_TO_TITLE
