#ifndef STACK_H
#define STACK_H

#include "Status.h"

template <class T>
class Stack {
public:
    Stack();
    Stack(const Stack & s);
    ~Stack();

    /********** ���¼�������Ϊ��ҵ��Ҫ��ʵ�ֵĻ������� **********/

    /**
     *  ��T���͵�ʵ��itemѹջ
     *  @param item: T���͵�һ��ʵ��
     */
    void push(const T & item);

    /**
     *  ����ջ��Ԫ�أ����ر�������Ԫ��
     *  @return    : ��������Ԫ��
     */
    T & pop();

    /**
     *  ��ȡջ��Ԫ��
     *  @return    : ջ��Ԫ��
     */
    const T & top() const;

    /**
     *  �ж�ջ�Ƿ�Ϊ��
     *  @return    : ���ջ�գ��򷵻�true�����򷵻�false
     */
    bool empty() const;


     /********** ���¼�������ΪΪ�˷������ӵĺ��� **********/

     /**
      *  ��ȡջ��������������ڹ��캯���б�����
      *  @return    : ��ǰջ���������
      */
    int getSize() const;

    /**
     *  ��ȡ��ǰջ��ջ��λ�ã����ڹ��캯���б�����
     *  @return    : ��ǰջ��ջ��λ��
     */
    int getTopPos() const;

    /**
     *  ��ȡ��ǰջ�е�iλ�õ�Ԫ�أ����ڹ��캯���б�����
     *  @param index: ��ȡԪ����ջ�е�λ��
     *  @return     : ��ǰջ��ջ��λ��
     */
    T at(int index) const;

    /**
     *  ���� = �ţ���sջ�е�ÿһ��Ԫ�ظ��ǵ��Լ��Ķ�Ӧλ��
     *  @param s: ���ڸ�ֵ��ջ
     */
    void operator= (const Stack & s);

private:
    /* ջ�ĳ�ʼ��С */
    static const int INIT_SIZE = 50;

    /* ջÿ������ռ�ʱ������ */
    static const int INCREMENT = 10;

    /* ���ڱ���ջ������Ԫ�� */
    T * items;

    /* ջ��ǰ�ѷ������� */
    int size;

    /* ջ��λ�� */
    int topPos;
};

template <class T>
Stack<T>::Stack() {
    size = INIT_SIZE;
    items = new T[size];
    topPos = 0;
}

template<class T>
Stack<T>::Stack(const Stack & s) {
    topPos = s.getTopPos();
    size = s.getSize();
    items = new T[size];
    for (int i = 0; i < topPos; i++) {
        items[i] = s.at(i);
    }
}

template <class T>
Stack<T>::~Stack() {
    delete[] items;
}

template<class T>
void Stack<T>::push(const T & item) {
    if (topPos == size) { // ��ǰջ������Ҫ��������
        T * newItems = new T[size + INCREMENT];
        for (int i = 0; i < size; i++) {
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
        size += INCREMENT;
    }
    items[topPos] = item;
    topPos++;
}

template<class T>
T & Stack<T>::pop() {
    if (topPos == 0) { // ջ��ʱ�޷�����ջ��Ԫ��
        throw ERROR;
    }
    topPos--;
    return items[topPos];
}

template<class T>
const T & Stack<T>::top() const {
    if (topPos == 0) { // ջ��ʱ�޷��鿴ջ��Ԫ��
        throw ERROR;
    }
    return items[topPos - 1];
}

template<class T>
inline bool Stack<T>::empty() const {
    return topPos == 0;
}

template<class T>
inline int Stack<T>::getSize() const {
    return size;
}

template<class T>
inline int Stack<T>::getTopPos() const {
    return topPos;
}

template<class T>
inline T Stack<T>::at(int index) const {
    return items[index];
}

template<class T>
void Stack<T>::operator=(const Stack & s) {
    topPos = s.getTopPos();
    size = s.getSize();
    for (int i = 0; i < topPos; i++) {
        items[i] = s.at(i);
    }
}

#endif // !STACK_H
