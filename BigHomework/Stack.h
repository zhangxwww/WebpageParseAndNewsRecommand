#ifndef STACK_H
#define STACK_H

#include "Status.h"

template <class T>
class Stack {
public:
    Stack();
    Stack(const Stack & s);
    ~Stack();

    /********** 以下几个函数为作业中要求实现的基本操作 **********/

    /**
     *  将T类型的实例item压栈
     *  @param item: T类型的一个实例
     */
    void push(const T & item);

    /**
     *  弹出栈顶元素，返回被弹出的元素
     *  @return    : 被弹出的元素
     */
    T & pop();

    /**
     *  获取栈顶元素
     *  @return    : 栈顶元素
     */
    const T & top() const;

    /**
     *  判断栈是否为空
     *  @return    : 如果栈空，则返回true，否则返回false
     */
    bool empty() const;


     /********** 以下几个函数为为了方便而添加的函数 **********/

     /**
      *  获取栈的最大容量，仅在构造函数中被调用
      *  @return    : 当前栈的最大容量
      */
    int getSize() const;

    /**
     *  获取当前栈的栈顶位置，仅在构造函数中被调用
     *  @return    : 当前栈的栈顶位置
     */
    int getTopPos() const;

    /**
     *  获取当前栈中第i位置的元素，仅在构造函数中被调用
     *  @param index: 获取元素在栈中的位置
     *  @return     : 当前栈的栈顶位置
     */
    T at(int index) const;

    /**
     *  重载 = 号，将s栈中的每一个元素覆盖到自己的对应位置
     *  @param s: 用于赋值的栈
     */
    void operator= (const Stack & s);

private:
    /* 栈的初始大小 */
    static const int INIT_SIZE = 50;

    /* 栈每次扩充空间时的增量 */
    static const int INCREMENT = 10;

    /* 用于保存栈的所有元素 */
    T * items;

    /* 栈当前已分配容量 */
    int size;

    /* 栈顶位置 */
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
    if (topPos == size) { // 当前栈满，需要扩充容量
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
    if (topPos == 0) { // 栈空时无法弹出栈顶元素
        throw ERROR;
    }
    topPos--;
    return items[topPos];
}

template<class T>
const T & Stack<T>::top() const {
    if (topPos == 0) { // 栈空时无法查看栈顶元素
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
