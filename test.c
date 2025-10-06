#include <stdio.h>
#include <stdlib.h>

#define MAX_CHILD 5
#define MAX_LINK  5

typedef struct Node {
    int value;
    struct Node* children[MAX_CHILD];
    int child_count;
} Node;

typedef struct Tree {
    Node* root;
    struct Tree* LinkTree[MAX_LINK];
    int link_count;
} Tree;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->child_count = 0;
    for (int i = 0; i < MAX_CHILD; i++)
        node->children[i] = NULL;
    return node;
}

void addChild(Node* parent, Node* child) {
    if (parent->child_count < MAX_CHILD)
        parent->children[parent->child_count++] = child;
}

Tree* createTree(Node* root) {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = root;
    tree->link_count = 0;
    for (int i = 0; i < MAX_LINK; i++)
        tree->LinkTree[i] = NULL;
    return tree;
}

void linkTree(Tree* from, Tree* to) {
    if (from->link_count < MAX_LINK)
        from->LinkTree[from->link_count++] = to;
}

void traverseNode(Node* node) {
    if (!node) return;
    printf("%d ", node->value);
    for (int i = 0; i < node->child_count; i++)
        traverseNode(node->children[i]);
}

void GBS(Tree* tree) {
    if (!tree) return;
    printf("\n[트리 탐색 시작]\n");
    traverseNode(tree->root);
    printf("\n");

    for (int i = 0; i < tree->link_count; i++) {
        printf("  └ 다른 트리로 이동 (%d번째 링크)\n", i + 1);
        GBS(tree->LinkTree[i]);
    }
}

int main(void) {
    Node* r1 = createNode(1);
    Node* a1 = createNode(2);
    Node* a2 = createNode(3);
    addChild(r1, a1);
    addChild(r1, a2);
    Tree* tree1 = createTree(r1);

    Node* r2 = createNode(10);
    Node* b1 = createNode(20);
    addChild(r2, b1);
    Tree* tree2 = createTree(r2);

    Node* r3 = createNode(100);
    Tree* tree3 = createTree(r3);

    linkTree(tree1, tree2);
    linkTree(tree2, tree3);

    printf("=== Garden 탐색 시작 ===\n");
    GBS(tree1);

    free(r1); free(a1); free(a2);
    free(r2); free(b1);
    free(r3);
    free(tree1); free(tree2); free(tree3);

    return 0;
}
