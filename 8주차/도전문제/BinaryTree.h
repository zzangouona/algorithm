//
// Created by 짱유나 on 2020/11/12.
//

#pragma once
#include "BinaryNode.h"
#include "CircularQueue.h"
//이진트리 클래스
//주석추가
class BinaryTree
{
    BinaryNode*	root; //루트 노드 포인터
public:

    //생성자 -> 새로운 트리 생성시 root null 초기화
    BinaryTree(): root(NULL) { }
    ~BinaryTree()	{ }

    void setRoot(BinaryNode* node)	{ root = node; }
    BinaryNode* getRoot()			{ return root; }

    //root가 공배 데이터(null)일 때 true/false
    bool isEmpty()	{ return root==NULL; }

    int	getCount()	{ return isEmpty() ? 0 : getCount(root); }
    int	getLeafCount(){ return isEmpty() ? 0 : getLeafCount(root); }
    int	getHeight()	{ return isEmpty() ? 0 : getHeight(root); }

    //순환 함수 접근
    void inorder()	{ cout<<endl<<"  inorder: "; inorder(root); }
    void preorder()	{ cout<<endl<<"  preorder: "; preorder(root); }
    void postorder(){ cout<<endl<<"  postorder: "; postorder(root); }

    //levelorder
    void levelorder( ) {
        //루트 노드 레벨이 1이고 아래로 내려갈수록 레벨이 증가를 한다.
        cout << endl <<"  levelorder: ";
        if( !isEmpty() ) {
            CircularQueue q; //큐 생성
            q.enqueue( root ); //트리의 루트 큐 삽입
            while ( !q.isEmpty() ) { //큐에 데이터가 완전히 없을때까지 반복
                BinaryNode* n = q.dequeue(); //맨앞 데이터 꺼냄
                if( n != NULL ) {//꺼낸데이터가 null이 아닐 경우
                    //동일한 레벨의 경우에는 좌에서 우로 방문한다. 큐를 사용한다.
                    cout <<" [" << (char)n->getData() <<"] "; //출력
                    q.enqueue(n->getLeft ());//왼쪽 노드 검사 및 큐에 삽입
                    q.enqueue(n->getRight());//오른쪽 노드 검사 및 큐에 삽입
                }
            }
        }
        cout << endl;
    }

    //전체 노드 개수
    int getCount(BinaryNode *node) {
        if (node == NULL) return 0; //노드가 null이면 함수 종료
        return 1 + getCount(node->getLeft()) + getCount(node->getRight());
        //개수 카운팅을 위해 트리 안의 노드들 전체적 순회
        //자기자신 + 왼쪽 오른쪽 카운팅 해준 값 반환
    }

    //단말 노드 개수
    int getLeafCount(BinaryNode *node) {
        if( node == NULL ) return 0; //노드기 null 이면 함수 종료
        if( node->isLeaf() ) return 1; //단말노드일 경우 1반환
        else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight()); //왼쪽 오른쪽 계산 후 합 반환
        // 자신은 단말노드 포함 아니여서 +1 안함
    }
    //높이
    int getHeight(BinaryNode *node)	{
        if( node == NULL ) return 0;
        int	hLeft  = getHeight(node->getLeft());
        int	hRight = getHeight(node->getRight());
        return (hLeft>hRight) ? hLeft+1 : hRight+1; //왼쪽 오른쪽 높이 구한후 더 큰것에 1(root 레벨)을 더해서 반환
    }

    //디렉토리용량계산
    int	calcSize()	{ return calcSize(root); }
    int calcSize(BinaryNode *node)	{
        if( node == NULL ) return 0;//node가 NULL이면 0 반환
        return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());//왼쪽 서브트리와 오른쪽 서브트리의 용량을 구하고 현재 용량을 더해 반환
    }

    int evaluate() { return evaluate(root); }
    // 수식 트리 계산 함수
    int evaluate(BinaryNode *node) {
        if( node == NULL ) return 0;//노드 NULL이면 0반환
        if( node->isLeaf() ) return node->getData();//단말 노드면 피연사자라서 그 노드 값 반환
        else {
            //왼쪽 서브트리 계산 후 결과 op1, 오른쪽 서브트리 계산 후 결과 op2에 저장하고 계산하고 반환
            int op1 = evaluate(node->getLeft());
            int op2 = evaluate(node->getRight());
            switch(node->getData()){
                case '+': return op1+op2;
                case '-': return op1-op2;
                case '*': return op1*op2;
                case '/': return op1/op2;
            }
            return 0;
        }
    }


private:
    // 트리의 순회

    //중위순회
    void inorder(BinaryNode *node) {
        if( node != NULL ) {//node가 NULL이 아닌 경우 실행
            //1. 왼쪽 서브트리 방문, 2. 루트 노드 처리, 3. 오른쪽 서브트리 방문
            if( node->getLeft() != NULL ) inorder(node->getLeft()); //왼쪽 서브 트리 처리
            cout <<" [" << (char)node->getData() <<"] "; //현재 노드 처리
            if( node->getRight()!= NULL ) inorder(node->getRight()); //오른쪽 서브트리 처리
        }
    }

    //전위 순회
    void preorder(BinaryNode *node) {
        if( node != NULL ) {//node가 NULL이 아닌 경우 실행
            //1. 루트 노드 처리, 2. 왼쪽 서브트리 방문, 3. 오른쪽 서브트리 방문
            cout <<" [" << (char)node->getData() <<"] ";
            if( node->getLeft() != NULL ) preorder(node->getLeft());
            if( node->getRight()!= NULL ) preorder(node->getRight());
        }
    }

    //후위순회
    void postorder(BinaryNode *node) {
        if( node != NULL ) {//node가 NULL이 아닌 경우 실행
            //1. 왼쪽 서브트리 방문, 2. 오른쪽 서브트리 방문, 3. 루트 노드 처
            if( node->getLeft() != NULL ) postorder(node->getLeft());
            if( node->getRight()!= NULL ) postorder(node->getRight());
            cout <<" [" << (char)node->getData() <<"] ";
        }
    }
};

