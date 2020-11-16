//
// Created by 짱유나 on 2020/11/16.
//

#pragma once

#include "Student.h"

#include <iostream>
using namespace std;

//#include <cstdlib>    //error 함수때문에 include


// 오류 에러메세지 호출 함수
// c++에서는 사용하지 않을꺼
//inline void error(const char* message) {  // const 키워드를 덧붙이지 않으면 문자열을 전달받을 수 없음
//    printf("%s\n", message);
//    exit(1);
//}

// 스택의 최대 크기
const int MAX_STACK_SIZE = 20;

class ArrayStack
{
private:
    int top; // 요소의 개수
    Student date[MAX_STACK_SIZE]; // 요소의 배열 // 학생의 정보를 저장할 Student 객체의 배열을 생성

public:
    // 생성자 // 배열은 0부터 시작하므로 초기값을 -1하고 추가시 +1을 한다
    ArrayStack() { top = -1; }
    ~ArrayStack() {}

    bool isEmpty() { return top == -1; } // 요소의 개수인 top이 -1이면 스택에 아무것도 안들어있다는것
    bool isFull() { return top == MAX_STACK_SIZE - 1; } // 요소의 개수인 top가 최대크기-1 만큼 들어있다면 스택이 꽉 차있다는 것

    // 데이터를 삽입
    // Student 타입의 데이터를 삽입 // 데이터가 크다면 포인터나 레퍼런스로 사용 가능
    void push(Student e)
    {
        // 스택공간이 포화상태일 경우 에러 출
        if (isFull()) cout << "스택 포화 에러"<<endl;

        // top을 먼저 +1 하고 배열에 데이터를 삽입
        date[++top] = e;
    }

    // 맨 위의 데이터를 삭제하고 반환(출력)
    // Student 타입의 데이터를 반환 -> 포인터나 레퍼런스로 처리 가
    Student pop()
    {
        // 스택공간이 비어있다면 에러 출력
        if (isEmpty()) cout << "스택 공백 에러"<<endl;

        // 데이터를 반환한후 top을 -1 처리
        return date[top--];
    }

    // 맨 위의 데이터를 삭제하지 않고 반환
    Student peek()
    {
        if (isEmpty()) cout << "스택 공백 에러"<<endl;

        // 데이터를 반환하고 top은 변화 없음.
        return date[top];
    }

    // 스택 데이터 출력 함수
    // 각 학생의 정보는 Student 클래스의 멤버함수를 사용
    void display()
    {
        cout << "[전체 학생의 수 = "<< top +1 << " ==> "<<endl;  // top이 -1부터 시작 시 +1을 한다
        for (int i = 0; i <= top; i++) // i<top을 하면 top-1만큼 실행하기 때문에 <= 으로 실행한다
            date[i].display();
        cout << endl;
    }
};
