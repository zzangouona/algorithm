//
// Created by 짱유나 on 2020/11/09.
//

#include <iostream>
using namespace std;

double power(double x, int n) {
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return power(x * x, n / 2);
    else
        return x*power(x * x, (n-1) / 2);
}

int main()
{
    int x, n;
    cout << "x의 n승 구하기 : ";
    cin >> x >> n;
    cout << power(x, n);
}

