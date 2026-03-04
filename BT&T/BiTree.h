#ifndef BI_TREE_H
#define BI_TREE_H
#include <stddef.h>

typedef struct BiNode{
    char data;
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode;
typedef struct BiTree{
    BiNode *root;
}BiTree;

typedef struct threadBiNode {
    BiNode node;
    int ltag;
    int rtag;
}threadBiNode, *threadBiTree;

/*ALL FUNCTIONS ARE ASSUMED THAT THE CALL IS LEGAL*/

//file: creatBiTree.c
BiNode* mkNode(char c);
BiTree* createBiTree(const char *s);

//file: taverse.c
void visit(const BiNode *p);
void preorder(BiTree *T, void (*visit)(const BiNode *p));
void inorder(BiTree *T, void (*visit)(const BiNode *p));
void posorder(BiTree *T, void (*visit)(const BiNode *p));

//file: height.c
int _height(BiNode *root);
int height(BiTree *T);

#endif