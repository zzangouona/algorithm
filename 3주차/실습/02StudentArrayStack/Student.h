//
// Created by 짱유나 on 2020/11/16.
//

#pragma once
#include <iostream>
using namespace std;

#define MAX_STRING 100

class Student
{
private:
    int id; // 학번
    char name[MAX_STRING]; // 이름
    char dept[MAX_STRING]; // 학과

public:
    Student(int i = 0, char* n = "", char* d = "") { set(i, n, d); }
    ~Student() {}

    void set(int i,char* n,char* d)
    {
        id = i;
        strcpy(name, n);
        strcpy(dept, d);
    }

    void display()
    {
        cout << " 학번 : "<< id <<" 성명 : "<<name <<" 학과 : "<< dept <<endl;

    }
};