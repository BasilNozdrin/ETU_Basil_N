#ifndef CUSTOMSTACK_H
#define CUSTOMSTACK_H

#include <iostream>
#include <cstring>

class CustomStack
{
public:
    CustomStack(size_t size = 10);
    ~CustomStack();

    void push(const char* val); // добавляет новый элемент в стек
    void pop(); // удаляет из стека последний элемент
    char* top(); // доступ к верхнему элементу
    size_t size(); // возвращает количество элементов в стеке
    bool empty(); // проверяет отсутствие элементов в стеке
    void extend(int n); // расширяет исходный массив на n ячеек

private:
    size_t mTopId;
    size_t mSize;

protected:
    char** mData;
};

#endif // CUSTOMSTACK_H
