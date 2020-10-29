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
            n->link = link;   // 그림 6.15의 (1)
            link = n;// 그림 6.15의 (2)
        }
    }
    Node* removeNext() {
        Node* removed = link;
        if (removed != NULL) link = removed->link; // 그림 6.16의 (1)
        return removed;
    }
};

class LinkedList {
    Node org; // 헤드 노드 ->  헤드 포인터 x
    int nodeSize;

public:
    LinkedList() : org(0), nodeSize(0) { }    // 생성자
    ~LinkedList() { clear(); }     // 소멸자

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
    void display(string str) {
        cout << str;
        cout <<"[전체 항목 수 = " << size() << "] : ";
        for (Node* p = getHead(); p != NULL; p = p->getLink())
            p->display();
        cout << endl;
    }

    //탐색 함수
    Node* find(int val) {
        for (Node* p = getHead(); p != NULL; p = p->getLink()) {
            if (p->hasData(val))return p;
        }
        return NULL;
    }

    //모든 노드 순서를 반대로 바꾸는 함수
    void reverse()
    {
        for (int i = 0; i < size(); i++) {
            Node* p = remove(size() - 1);
            insert(i, p);
        }
    }

    //두 리스트를 병합하는 함수
    void merge(LinkedList* that) {
        while (!that->isEmpty()) {
            Node* p = that->remove(0);
            insert(size(), p);
        }
    }
};


int main()
{
    LinkedList list, list2;         // 리스트 객체 생성
    list.insert(0, new Node(10));     // 리스트 맨 앞에 10 삽입
    list.insert(0, new Node(20));     // 리스트 맨 앞에 20 삽입
    list.insert(1, new Node(30));     // 리스트 1위치에 30 삽입
    list.insert(list.size(), new Node(40)); // 리스트 마지막에 40 삽입
    list.insert(2, new Node(50));     // 리스트 1위치에 50 삽입
    list.display("List(전)");             // 리스트내용 화면출력
    list.reverse();
    list.display("List(후)");

    list2.insert(0, new  Node(70));
    list2.insert(1, new  Node(80));
    list2.insert(2, new  Node(90));
    list2.display("List(that)");

    list.merge(&list2);
    list.display("List(Reverse+that");
    list2.display("List(that)");

    list.clear();
    list2.clear();
    list.display("끝");
    return 0;
}
