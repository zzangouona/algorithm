//
// Created by 짱유나 on 2020/11/10.
//
#include<iostream>
#include<ctime>

using namespace std;

//반복적인 거듭제곱함수
double slowPower(double x, int n) {
    double result = 1.0;
    for (int i = 0; i < n; i++) result = result * x;
    return result;
}

//순환적인 거듭제곱함
double Power(double x, int n) {
    if (n == 0) return 1;
    else if (n % 2 == 0) { return Power(x * x, n / 2); }//n = 짝수
    else { return x * Power(x * x, (n - 1) / 2); }//n = 홀
}

int main() {
    clock_t start = clock();
    Power(2, 5000);
    clock_t end = clock();
    cout << "power 함수 시간: " << "(" << end - start << "ms)" << endl;

    start = clock();
    slowPower(2, 5000);
    end = clock();
    cout << "slowPower 함수 시간: " << "(" << end - start << "ms)" << endl;


    return 0;
}