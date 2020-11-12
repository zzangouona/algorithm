#include "BinaryTree.h"
#include <cstdio>

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

    printf("\n  노드의 개수 : %d", tree.getCount());
    printf("\n  단말 노드의 개수 : %d", tree.getLeafCount());
    printf("\n  트리의 높이 : %d", tree.getHeight());

    printf("\n");

    return 0;
}