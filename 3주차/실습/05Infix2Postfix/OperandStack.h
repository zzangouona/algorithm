//
// Created by 짱유나 on 2020/11/17.
//
#pragma once
#include <iostream>
using namespace std;

// 오류 에러메세지 호출 함수
// c++에서는 사용하지 않을꺼
inline void error(char* message)   // 에러메세지를 포인터로 받아서 출력하는 함수
{
    cout << message << endl;
}


#define MAX_STACK_SIZE 20

class OperandStack
{
private:
    int top;
    double date[MAX_STACK_SIZE];

public:
    OperandStack() { top = -1; }
    ~OperandStack() {}

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_STACK_SIZE - 1; }

    void push(double d)
    {
        if (isFull())
            error("스택 공간이 꽉 찼습니다");

        date[++top] = d;
    }

    double pop()
    {
        if (isEmpty())
            error("스택 공간이 다 비워져 있습니다");

        return date[top--];
    }

    char peek()
    {
        if (isEmpty())
            error("스택 공간이 다 비워져 있습니다");

        return date[top];
    }
};
