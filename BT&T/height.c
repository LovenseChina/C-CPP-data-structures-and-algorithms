#include "BiTree.h"

int _height(BiNode *root) {
    if(!root)
        return 0;
    int l = _height(root->lchild), r = _height(root->rchild);
    return 1 + (l > r ? l : r);
}

int height(BiTree *T) {
    if(!T)
        return 0;
    return _height(T->root);
}