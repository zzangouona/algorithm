//
// Created by 짱유나 on 2020/11/16.
//

#include <iostream>
#include <fstream>
#include "ArrayStack.h"
using namespace std;

bool checkMatching(char *filename) {
    // 주어진 파일을 읽어 괄호 매칭을 검사하고 결과를 출력하는 함수
    ifstream file(filename);
    if (!file) {
        cout << "Error: 파일이 존재하지 않습니다." << endl;
    }

    int nLine = 1; // 읽은 라인의 개수
    int nChar = 0; // 읽은 문자 개수
    ArrayStack stack; // 스택 객체
    char ch;

    while (file.eof() == false) {	// 파일의 끝(End Of File)이 나타날 때까지 반복, getc()는 문자입력함수
        ch = file.get();
        if (ch == '\n')
            nLine++;      // 줄바꿈이 있으면, 읽은 라인 +1
        nChar++;   // 문자개수 +1


        //파일 괄호 검사
        if (ch == '[' || ch == '(' || ch == '{')   // 왼쪽 괄호를 받으면,
            stack.push(ch);   // Stack에 push함
        else if (ch == ']' || ch == ')' || ch == '}')    // 오른쪽 괄호가 들어오면,
        {
            char prev = stack.pop();
            if ((ch == ']' && prev != '[')
                || (ch == ')' && prev != '(')
                || (ch == '}' && prev != '{'))   // 가장 최근에 push했던 값을 pop해서 비교
                break;   // 짝이 맞으면 넘어가고 아니면 반복문을 빠져나감
        }
    }

    file.close();   // File을 Close 하는 방법
    cout <<"["<< filename << "] 파일 검사 결과: "<<endl;
    if (!stack.isEmpty()) {
        cout << "Error : 문제 발견! (라인수=" << nLine << ", 문자수=" << nChar << ')' << endl;
    }
    else
        cout << "Ok : 괄호닫기정상 (라인수=" << nLine << ", 문자수=" << nChar << ')' << endl;

    return stack.isEmpty();
}

int main()
{
    checkMatching((char*)"ArrayStack.h");
    checkMatching((char*)"CheckingMatching.cpp");
}

