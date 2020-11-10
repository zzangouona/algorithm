//
// Created by 짱유나 on 2020/11/09.
//
#include <iostream>
using namespace std;

#define WIDTH 20
#define HEIGHT 9

//다중함수 호출 함수
void labelComponent(unsigned char img[HEIGHT][WIDTH],int x,int y,int label){
    if( x<0 || y<0 || x>=WIDTH || y>=HEIGHT ) return;//이미지 크기 보다 크면 영상의 밖이면 나간다

    if( img[y][x] == 9 ) {// 처리가 안된 전경 화소이면
        img[y][x] = label; // label로 화소 값을 바꾸고
        //순환 호출
        labelComponent( img, x-1, y, label ); // 순환 호출 왼쪽
        labelComponent( img,  x, y-1, label ); // 순환 호출 위
        labelComponent( img, x+1, y, label ); // 순환 호출 오른쪽
        labelComponent( img,  x, y+1, label ); // 순환 호출 아래

    }
}


// 이진 영상의 영역 채색(blob coloring) 함수
void blobColoring(unsigned char img[HEIGHT][WIDTH]){
    int label = 1; // label은 1부터 시작함
    // 영상의 모든 화소에 대해
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (img[y][x] == 9)// 처리가 안 된 전경 화소이면
                labelComponent(img, x, y, label++);// 연결화소 채색 시작
        }
    }
}


void printImage(unsigned char img[HEIGHT][WIDTH], string msg) {
    cout << msg << endl;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (img[y][x] == 0)
                cout << '*';
            else
                cout << img[y][x];
        }
        cout << '\n';
    }
    cout << '\n';
}


int main()
{
    unsigned char image[HEIGHT][WIDTH] = {
            0,0,0,0,0,0,9,0,0,0,0,9,9,9,9,0,0,9,9,0,
            9,9,9,9,9,0,9,0,0,0,0,0,0,0,0,9,0,0,9,9,
            0,0,9,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
            0,9,9,9,0,0,9,9,9,0,0,9,0,0,0,0,0,0,9,9,
            9,9,0,9,9,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
            9,9,0,9,9,0,9,0,0,0,0,0,0,0,0,0,0,0,9,9,
            9,0,0,0,9,0,9,0,0,0,0,0,9,0,9,0,0,0,0,0,
            9,0,0,0,9,0,9,0,0,0,0,0,9,0,9,0,0,0,9,9,
            0,0,0,0,0,0,9,0,0,0,9,9,9,9,9,9,0,0,9,9
    };
    printImage(image, "<Original image>");
    blobColoring(image);
    printImage(image, "<Labelled image>");
}

