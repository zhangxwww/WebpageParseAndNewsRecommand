#ifndef CHAR_STRING_HASH_TABLE_H
#define CHAR_STRING_HASH_TABLE_H

#include "CharString.h"
#include "CharStringLink.h"

/**
 *  �������Լ�ʵ�ֵĹ�ϣ��hash�㷨���õ���time33�㷨
 *  ��ϣ��ͻ������ַ�����
 */
class CharStringHashTable {
public:
    CharStringHashTable();
    CharStringHashTable(const CharStringHashTable & csht);
    ~CharStringHashTable();

    /**
     *  �ڹ�ϣ��������µ�key
     *  @param cs: Ҫ��ӵ�key
     */
    void add(const CharString & cs);


    /**
     *  �ڹ�ϣ��������key
     *  @param cs: Ҫ�������ַ���
     *  @return  : ����������key���򷵻�true�����򷵻�false
     */
    bool find(const CharString & cs) const;


    /**
     *  ���ع�ϣ����indexλ�õ�����ֻ�ڹ��캯���б�����
     *  @param index: ��Ҫ���ҵ����������
     *  @return     : ��Ӧλ�õ�����
     */
    const CharStringLink & at(const int index) const;

private:
    /**
     *  ��ϣ�㷨������time33
     *  @param cs: key
     *  @return  : key��Ӧ�Ĺ�ϣֵ
     */
    int hash(const CharString & cs) const;

    /* ��ϣ���С�����ݴʿ��С��ѡ���1E6���������� */
    static const int HASH_SIZE = 1000003;

    /* ���е����� */
    CharStringLink * cslinks;
};

#endif // !CHAR_STRING_HASH_TABLE_H
