#ifndef STACK_8_1_H
#define STACK_8_1_H
#include <cassert>

const int maxStackSize = 1000;

template<class StackElementType>
class Stack{
public:
    Stack();//생성자는 멤버변수 초기화 공간의 할당
    void push(StackElementType item);
    StackElementType pop();
    StackElementType top();
    bool isEmpty();
private:
    StackElementType stackArray[maxStackSize];
    int topIndex;
};

#endif //STACK_8_1_H
template <class StackElementType>
Stack <StackElementType> :: Stack()
{
    topIndex = -1;
}
template <class StackElementType>
void
Stack <StackElementType> ::push(StackElementType item)
{
    ++topIndex; // topIndex = -1이므로 먼저 올려주고 할당해야함
    assert(topIndex < maxStackSize); // 배열의 크기는 제한되어있음
    stackArray[topIndex] = item;
}

template <class StackElementType>
StackElementType
Stack <StackElementType> :: pop()
{
    assert(topIndex >= 0); // push이후 Pop을 한다면 topindex가 데이터가 있는 곳을 가르킴
    int returnIndex(topIndex);
    --topIndex;
    return stackArray[returnIndex];
}

template <class StackElementType>
StackElementType
Stack <StackElementType> :: top() // pop 과 버리냐 안버리냐 차이
{
    assert(topIndex >= 0);
    return stackArray[topIndex];
}

template <class StackElementType>
bool
Stack <StackElementType> :: isEmpty()
{
    return bool(topIndex == -1);
}