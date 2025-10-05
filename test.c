#include <stdio.h>
#include <stdlib.h>

#define MAX_LINK 10

typedef struct Tree {
    int root;
    int node2;
    int node3;
    struct Tree* LinkTree[MAX_LINK];
    int link_count;
} Tree;

void GDS(Tree* node) {
    if (!node) return;

    printf("노드 탐색: %d %d %d\n", node->root, node->node2, node->node3);

    for (int i = 0; i < node->link_count; i++) {
        GDS(node->LinkTree[i]);
    }
}

int main(void) {
    Tree* tree1 = (Tree*)malloc(sizeof(Tree));
    Tree* tree2 = (Tree*)malloc(sizeof(Tree));
    Tree* tree3 = (Tree*)malloc(sizeof(Tree));
    Tree* tree4 = (Tree*)malloc(sizeof(Tree));

    tree1->root = 1;   tree1->node2 = 35;  tree1->node3 = 32; tree1->link_count = 2;
    tree2->root = 21;  tree2->node2 = 23;  tree2->node3 = 53; tree2->link_count = 1;
    tree3->root = 3;   tree3->node2 = 8;   tree3->node3 = 9;  tree3->link_count = 0;
    tree4->root = 6;   tree4->node2 = 153; tree4->node3 = 45; tree4->link_count = 0;

    tree1->LinkTree[0] = tree2;
    tree1->LinkTree[1] = tree3;
    tree2->LinkTree[0] = tree4;

    printf("GDS 탐색 결과:\n");
    GDS(tree1);

    free(tree1);
    free(tree2);
    free(tree3);
    free(tree4);

    return 0;
}
