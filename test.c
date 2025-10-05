#include <stdio.h>
#include <stdlib.h>

#define MAX 9

typedef struct Tree {
    int node1;
    int node2;
    int node3;
    struct Tree* leaf1;
    struct Tree* leaf2;
} Tree;

void LinkTree_leaf1(Tree* tree1, Tree* tree2) {
    tree1->leaf1 = tree2;
}

void LinkTree_leaf2(Tree* tree1, Tree* tree2) {
    tree1->leaf2 = tree2;
}

int main(void) {
    Tree* tree1 = (Tree*)malloc(sizeof(Tree));
    Tree* tree2 = (Tree*)malloc(sizeof(Tree));

    tree1->node1 = 40;
    tree1->node2 = 50;
    tree1->node3 = 60;

    tree2->node1 = 10;
    tree2->node2 = 20;
    tree2->node3 = 30;

    LinkTree_leaf1(tree1, tree2);

    printf("Tree1 Root node1: %d\n", tree1->node1);
    printf("Tree1 leaf1 -> Tree2 node1: %d\n", tree1->leaf1->node1);

    free(tree1);
    free(tree2);

    return 0;
}
