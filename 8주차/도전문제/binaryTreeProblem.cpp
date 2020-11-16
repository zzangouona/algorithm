#include "BinaryTree.h"


int main()
{
    BinaryTree tree;
    BinaryNode *d = new BinaryNode('D', NULL, NULL);
    BinaryNode *b = new BinaryNode('B', d, NULL);
    BinaryNode *g = new BinaryNode('G', NULL, NULL);
    BinaryNode *h = new BinaryNode('H', NULL, NULL);
    BinaryNode *e = new BinaryNode('E', g, h);
    BinaryNode *f = new BinaryNode('F', NULL, NULL);
    BinaryNode *c = new BinaryNode('C', e, f);
    BinaryNode *a = new BinaryNode('A', b, c);


    // 루트
    tree.setRoot(a);

    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.levelorder();


    cout << endl << "  노드의 개수 : " << tree.getCount();
    cout << endl << "  단말 노드의 개수 : " << tree.getLeafCount();
    cout << endl << "  트리의 높이 : "  <<tree.getHeight();

    cout << endl;

    return 0;
}