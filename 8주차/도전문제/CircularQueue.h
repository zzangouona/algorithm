//
// Created by 짱유나 on 2020/11/12.
//
#pragma once
#include "BinaryNode.h"

#define MAX_QUEUE_SIZE	100

class CircularQueue
{
    int			front;// 첫 번째 요소의 앞의 위치 (전단) (삭제를 위한 변수)
    int			rear; // 마지막 요소 위치 (후단) (삽입을 위한 변수)
    BinaryNode*	data[MAX_QUEUE_SIZE];
public:
    CircularQueue()	{ front = rear = 0; }
    ~CircularQueue() { }
    bool isEmpty()	{ return front == rear; } // front == rear 이 되면 공백상태
    bool isFull()	{ return (rear+1)%MAX_QUEUE_SIZE == front; } // front가 rear보다 한칸 앞에 있으면 포화상태

    // 삽입 : 연결된 큐의 맨 뒤에 노드 삽입
   void enqueue( BinaryNode* n ) {
        if( isFull() ) cout << "큐가 포화상태입니다" <<endl;
        else {
            rear = (rear+1) % MAX_QUEUE_SIZE;
            data[rear] = n;
        }
    }

    // 삭제 : 연결된 큐의 맨 앞 노드를 삭제
    BinaryNode* dequeue( ) {
        if( isEmpty() ) cout << "큐가 공백상태입니다" <<endl;
        else {
            front = (front+1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }
};
