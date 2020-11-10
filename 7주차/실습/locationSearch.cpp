//
// Created by 짱유나 on 2020/11/09.
//

#include <iostream>

using namespace std;

const int MAZE_SIZE = 6;//고정크기


char map[MAZE_SIZE][MAZE_SIZE] = { //미로맵데이터
        {'1','1','1','1','1','1'},
        {'e','0','1','0','0','1'},
        {'1','0','0','0','1','1'},
        {'1','0','1','0','1','1'},
        {'1','0','1','0','0','x'},
        {'1','1','1','1','1','1'}
};

struct Location2D {
    int row;
    int col;


    Location2D(int r = 0, int c = 0) { row = r; col = c; }


    bool isNeighbor(Location2D& p) {
        return ((row == p.row && (col == p.col - 1 || col == p.col + 1)) ||
                (col == p.col) && (row == p.row - 1 || row == p.row + 1));
    }

    bool operator==(Location2D& p) { return row == p.row && col == p.col; }
};

bool isValidLoc(int r, int c) {
    if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE)
        return false;
    else
        return map[r][c] == '0' || map[r][c] == 'x';
}

//입구와 출구
Location2D locEntry, locExit;
//bool done : 탐색 성공 실패  -> 탐색을 성공하면 순환호출 멈추고 true로 값 변경
bool done = false;

//미로탐색함수 : 순환
void searchRecur(Location2D pt) {

    cout << pt.row << "," << pt.col<<' '; //현재 위치 출력
    if (done) return;//탐색 성공 시 종료
    if (pt == locExit) {//현재 위치가 출구시 탐색 done = true, 탐색 성
        done = true;
        return;
    }

    int r = pt.row;
    int c = pt.col;
    map[r][c] = '5';

    //네방향 순환호
    if (isValidLoc(r - 1, c)) searchRecur(Location2D(r - 1, c));//위
    if (isValidLoc(r + 1, c)) searchRecur(Location2D(r + 1, c));//아래
    if (isValidLoc(r, c+1)) searchRecur(Location2D(r - 1, c+1));//왼쪽
    if (isValidLoc(r, c-1)) searchRecur(Location2D(r - 1, c-1));//오른쪽

}

int main()
{

    locEntry = Location2D(1, 0);
    locExit = Location2D(4, 5);

    searchRecur(locEntry);

    if (done)
        cout << "\n===>출구가 탐지되었습니다. \n";
    else
        cout << "\n===>출구를 찾지못했습니다.\n";

}
