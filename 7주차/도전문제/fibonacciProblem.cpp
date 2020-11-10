#include "iostream"
using namespace std;

int fibo(int* cnt, int n){
    cnt[n]++;
    if (n == 0)  return 0;
    if (n == 1) return 1;
    return (fibo(cnt, n - 1) + fibo(cnt, n - 2));
}

int main(){
    int num;
    cout << "n = ";
    cin >> num;
    int* cnt = new int[num + 1];
    //초기화
    for (int i = 0; i < num + 1; i++)
        cnt[i] = 0;

    fibo(cnt, num);

    //출
    for (int i = num; i >= 0; i--)
        cout << "Fibo(" << i << ") = " << cnt[i] << "번" << endl;

    delete[] cnt; //동적메모리 cnt 삭제

    return 0;
}