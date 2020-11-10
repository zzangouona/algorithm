#include <iostream>
using namespace std;

class Node {
    Node* link;
    int data;

public:
    Node(int val = 0) : data(val), link(NULL) { }
    Node* getLink() { return link; }
    void setLink(Node* next) { link = next; }
    void display() { cout<<"<"<<data<<"> "; }
    bool hasData(int val) { return data == val; }
    void insertNext(Node* n) {
        if (n != NULL) {
            n->link = link;
            link = n;
        }
    }
    Node* removeNext() {
        Node* removed = link;
        if (removed != NULL) link = removed->link;
        return removed;
    }
};

class LinkedList {
    Node org; // 헤드 노드 ->  헤드 포인터 x
    int nodeSize;

public:
    LinkedList() : org(0), nodeSize(0) { }
    ~LinkedList() { clear(); }

    void clear() {
        while (!isEmpty())
            delete remove(0);
        nodeSize = 0;
    }
    bool isEmpty() { return getHead() == NULL; }
    Node* getHead() { return org.getLink(); }


    // pos번째 항목을 반환함
    Node* getEntry(int pos) {
        Node* n = &org;
        for (int i = -1; i < pos; i++, n = n->getLink()) {
            if (n == NULL) break;
        }
        return n;
    }

    //리스트 항목 개수를 반환
    int size() {
        return nodeSize;
    }

    //리스트의 pos번째 노드를 다른 노드로 교체.
    void replace(int pos, Node* n) {
        Node* prev = getEntry(pos - 1);
        if (prev != NULL) {
            delete prev->removeNext();
            prev->insertNext(n);
        }
    }

    // 리스트의 어떤 위치에 항목 삽입
    void insert(int pos, Node* n) {
        Node* prev = getEntry(pos - 1);
        if (prev != NULL)
            prev->insertNext(n);
        nodeSize++;
    }

    // 리스트의 어떤 위치의 항목 삭제
    Node* remove(int pos) {
        nodeSize--;
        Node* prev = getEntry(pos - 1);
        return prev->removeNext();
    }

    // 화면에 보기 좋게 출력
    void display() {
        printf("[전체 항목 수 = %2d] : ", size());
        for (Node* p = getHead(); p != NULL; p = p->getLink())
            p->display();
        printf("\n");
    }

    //탐색 함수
    Node* find(int val) {
        for (Node* p = getHead(); p != NULL; p = p->getLink()) {
            if (p->hasData(val))return p;
        }
        return NULL;
    }


};


int main()
{
    LinkedList list;				//리스트 객체 생성.
    list.insert(0, new Node(10));			//리스트 맨 앞에 10 삽입.
    list.insert(0, new Node(20));			//리스트 맨 앞에 20 삽입.
    list.insert(1, new Node(30));			//리스트 1위치에 30 삽입.
    list.insert(list.size(), new Node(40));			//리스트 마지막에 40 삽입.
    list.insert(2, new Node(50));			//리스트 2위치에 50 삽입.
    list.display();
    list.remove(2);				//리스트 2위치의 항목 삭제.
    list.remove(list.size() - 1);		//리스트 마지막 항목 삭제.
    list.remove(0);
    list.replace(1, new Node(90));		//리스트 1위치 항목 값 변경(대체).
    list.display();
    list.clear();					//리스트 내 항목 모두 삭제.
    list.display();
    return 0;
}
