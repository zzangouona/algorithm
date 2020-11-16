//
// Created by 짱유나 on 2020/11/16.
//

#include "ArrayStack.h"
#include "Student.h"

int main()
{
    ArrayStack stack;
    Student s(200012345, "정윤아", "미디어경영학과");
    stack.push(s);
    stack.display();

    s.set(201613096, "시우민", "미디어경영학과");
    stack.push(s);
    stack.display();

    //또 다른 선언 방법
    //임시 객체를 만들어 전달 후 임시객체 삭제
    stack.push(Student(123456789, "변백현", "미디어경영학과"));
    stack.display();

    stack.pop();
    stack.display();

    return 0;
}