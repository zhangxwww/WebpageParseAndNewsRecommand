#ifndef STACK_H
#define STACK_H

#include "Status.h"

template <class T>
class Stack {
public:
    Stack();
    Stack(const Stack & s);
    ~Stack();

    void push(const T & item);
    T & pop();
    const T & top() const;
    bool empty() const;

    int getSize() const;
    int getTopPos() const;
    T at(int index) const;
    void operator= (const Stack & s);

private:
    static const int INIT_SIZE = 50;
    static const int INCREMENT = 10;
    T * items;
    int size;
    int topPos;
};

template <class T>
Stack<T>::Stack() {
    size = INIT_SIZE;
    items = new T[size];
    topPos = 0;
}

template<class T>
Stack<T>::Stack(const Stack & s)
{
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
void Stack<T>::push(const T & item)
{
    if (topPos == size) { // stack overflow
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
T & Stack<T>::pop()
{
    if (topPos == 0) {
        throw ERROR;
    }
    topPos--;
    return items[topPos];
}

template<class T>
const T & Stack<T>::top() const
{
    if (topPos == 0) {
        throw ERROR;
    }
    return items[topPos - 1];
}

template<class T>
inline bool Stack<T>::empty() const
{
    return topPos == 0;
}

template<class T>
inline int Stack<T>::getSize() const
{
    return size;
}

template<class T>
inline int Stack<T>::getTopPos() const
{
    return topPos;
}

template<class T>
inline T Stack<T>::at(int index) const
{
    return items[index];
}

template<class T>
void Stack<T>::operator=(const Stack & s)
{
    topPos = s.getTopPos();
    size = s.getSize();
    for (int i = 0; i < topPos; i++) {
        items[i] = s.at(i);
    }
}

#endif // !STACK_H
