//
// Created by 짱유나 on 2020/11/16.
//
#pragma once
#include <iostream>
using namespace std;

// 오류 에러메세지 호출 함수
// c++에서는 사용하지 않을꺼
inline void error(char* message)   // 에러메세지를 포인터로 받아서 출력하는 함수
{
    cout << message << endl;
    //exit(1);
}


const int MAX_STACK_SIZE = 20;    // 스택의 최대 크기 설정(#define인 매크로 방식도 가능)

class ArrayStack {
// 접근지정자를 설정하지 않을 시 자동 private
    int top;                     // 요소의 개수
    int data[MAX_STACK_SIZE];    // 요소의 배열

public:
    // 스택 생성자 - 새로운 객체가 생성되면 자동 호출, 멤버변수 초기화
    ArrayStack() { top = -1;  *data = NULL; }    // 생성자에서 data 변수를 초기화하지 않으면 컴파일이 안 되는 것은 아니지만 경고가 출력됨

    // 스택 소멸자 - 아무 일도 안하면 생략가능
    // ~ArrayStack() {}


    bool isEmpty() { return top == -1; }  // 스택의 공백 상태 반환 함수


    bool isFull() { return top == MAX_STACK_SIZE - 1; } // 스택의 포화 상태 반환 함수

    // 스택 삽입 : 맨 위에 요소 삽입
    void push(int e) {
        if (isFull()) cout << "스택 포화 에러"<<endl;
        data[++top] = e;
    }

    // 스택 삭제 : 맨 위의 요소를 삭제하고 반환
    int pop() {
        if (isEmpty()) cout << "스택 공백 에러"<< endl;
        return data[top--];
    }

    // 맨 위에 요소 반환함수 -> 삭제 x 출력
    int peek() {
        if (isEmpty()) cout << "스택 공백 에러"<<endl;
        return data[top];    // top 변수의 변화없음
    }

    // 출력
    void display() {
        cout <<"[스택 항목 수 : " << top +1 << "] ==> ";
        for (int i = 0; i <= top; i++) {	// 반복문의 종료조건(i<=top)에 유의
            cout <<"<"<<data[i]<<">";
        }
        cout<<endl;
    }
};
