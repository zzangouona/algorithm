
#include <iostream>
using namespace std;
//순환
void reverse(string n, int i) {//2
    if (i == n.length())//3
        return;//423 반복되다가 i가 4일때 순환 종료
    reverse(n, i+1);//4
    cout<<n[i];//마지막에 출력
}

int main() {

   reverse("ABCDE",0);//1
}