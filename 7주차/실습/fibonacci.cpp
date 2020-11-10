//
// Created by 짱유나 on 2020/11/09.
//

#include <iostream>

using namespace std;

int Fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return Fibonacci(n - 2) + Fibonacci(n - 1);
}

int main()
{
    int n;
    cout << "피보나치 구하기 : ";
    cin >> n;
    cout << Fibonacci(n);
}
