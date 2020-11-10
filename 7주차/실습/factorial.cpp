//
// Created by 짱유나 on 2020/11/09.
//

#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 1)
        return 1;

    return factorial(n - 1) * n;
}

int main()
{
    int n;
    cout << "팩토리얼 구하기 : ";
    cin >> n;
    cout << factorial(n);
}

