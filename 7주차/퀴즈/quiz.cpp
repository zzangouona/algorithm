#include <iostream>
using namespace std;

//1번
int recursive_01(int n){
    if (n == 1) return 1;
    return n * recursive_01(n - 1);
}

//2번
int recursive_02(int n){
    cout << n << endl;
    if (n == 1) return 1;
    return n * recursive_02(n - 1);
}

//3번
int sum_03(int n){
    cout << n << endl;
    if (n < 1) return 0;
    else return (n + sum_03(n - 1));
}
//4번
void asterisk(int i){
    if (i > 1) {
        asterisk(i / 2);
        asterisk(i / 2);
    }
    cout << "*";
}


//5번
int sum_05(int n){
    if (n == 1)
        return 1;
    else
        return n + sum_05(n - 1);
}

int main(){
	int num;
	cout << "n을 입력하세요.";
	cin >> num;
	cout << "" << sum_05(num) << endl;
	return 0;
}


//6번
//분수
double sum_06(int n){
    if (n == 1)
        return 1;
    else
        return (1 / (double)n) + sum_06(n - 1);
}

//int main()
//{
//    int num;
//    cout << "n을 입력하세요. ";
//    cin >> num;
//    cout << "답 : " << sum_06(num) << endl;
//    return 0;
//}

