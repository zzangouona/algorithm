//
// Created by 짱유나 on 2020/11/16.
//

#include "ArrayStack.h"// ArrayStack 클래스 포함

int main()
{
    ArrayStack stack;
    for( int i=1 ; i<10 ; i++ )
        stack.push( i );
    stack.display();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.display();
    return 0;
}
