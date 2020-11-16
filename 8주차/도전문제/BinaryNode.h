//
// Created by 짱유나 on 2020/11/12.
//

#pragma once
#include <iostream>
using namespace std;

//이진노드 클래스
class BinaryNode{
protected://상속을 고려하여 데이터 멤버를 protected로 선언
    int			data; //데이터
    BinaryNode	*left; //왼쪽자식 포인터 변수
    BinaryNode	*right; //오른쪽자식 포인터 변수
public:
    //생성자
    BinaryNode( int val=0, BinaryNode *l=NULL, BinaryNode *r=NULL)
            : data(val), left(l), right(r) { }
    ~BinaryNode()	{ }

    //데이터멤버 설정
    void		setData ( int val )		{ data	= val; }
    void		setLeft (BinaryNode *l)	{ left	= l; }
    void		setRight(BinaryNode *r)	{ right	= r; }

    //데이터멤버 반환
    int			getData ()				{ return data; }
    BinaryNode*	getLeft ()				{ return left; }
    BinaryNode*	getRight()				{ return right; }

    bool		isLeaf()	{ return left==NULL && right==NULL; } //단말노드 검사 함수
};

