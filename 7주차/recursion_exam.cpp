//
// Created by 짱유나 on 2020/11/04.
//

#include <iostream>
using namespace std;

void foo(){
    cout <<"foo"<<endl;
    //if(0)
        foo();
}

int main(){
    foo();
}