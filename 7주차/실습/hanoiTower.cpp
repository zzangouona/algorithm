//
// Created by 짱유나 on 2020/11/10.
//


//하노이탑문제
#include <iostream>
using namespace std;

//from-> first, tmp -> second, to -> third
void hanoiTower(int n, char from, char tmp, char to){

    if (n == 1)//첫번째에 있는 n개의 원판을 세번째 원판을 이용해 두번째 원판으로 이동한다.
        cout << "원판 1을 ›" << from << "에서 "<< to << "으로 옮긴다" << endl;

    else
    {
        hanoiTower(n - 1, from, to, tmp); // A에 있는 원판 중 맨 마지막 원판을 제외한 N-1개의 막대들을 두 번째 막대에 모두 옮긴다.
        cout << "원판 "<<n<<"을 " << from << "에서 "<< to << "으로 옮긴다" << endl;//A에 있는 원판 하나를 C로 옮긴다.
        hanoiTower(n - 1, tmp, from, to);// B에 옮겨 던 N-1개의 막대들을 다시 C로 옮겨준다.
    }
}
int main()
{
    hanoiTower(3, 'A', 'B', 'C');
    return 0;
}

