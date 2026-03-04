#include"Recursive_Algo.h"
#include<stdlib.h>

/* BST */
BSTNode *_new_BSTNode(int key) {
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    node->key = key;
    node->lchild = node->rchild = NULL;
    return node;
}

BSTNode *insert_BSTNode(BSTNode *root,int key) {
    if(root == NULL)
        return _new_BSTNode(key);
    else if(root->key == key)
        return root;
    else if(root->key > key)
        root->lchild = insert_BSTNode(root->lchild, key);
    else
        root->rchild = insert_BSTNode(root->rchild, key);
    return root;
}

BSTNode *erase_BSTNode(BSTNode *root, int key) {
    if(root == NULL)
        return NULL;
    else if(root->key > key)
        root->lchild = erase_BSTNode(root->lchild, key);
    else if((root->key < key))
        root->rchild = erase_BSTNode(root->rchild, key);
    else {
        if(root->lchild == NULL || root->rchild == NULL) {
            BSTNode *ret = root->lchild ? root->lchild : root->rchild;
            free(root);
            return ret;
        }
        else {
            BSTNode *pre = root->lchild;
            while(pre->rchild)
                pre = pre->rchild;
            root->key = pre->key;
            root->lchild = erase_BSTNode(root->lchild, pre->key);
        }
    }
    return root;
}

int search_BST(BSTNode *root, int key) {
    if(!root)
        return 0;
    else if(root->key == key)
        return 1;
    else if(root->key > key)
        return search_BST(root->lchild, key);
    else
        return search_BST(root->rchild, key);
}


/* AVL */
AVLNode *_new_AVLNode(int key) {
    AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
    node->key = key;
    node->height = 1;
    node->lchild = node->rchild = NULL;
    return node;
}

void _height_update_AVLNode(AVLNode *root) {
    if(!root)
        return;
    if(root->lchild && root->rchild)
        root->height = (root->lchild->height > root->rchild->height ?
            root->lchild->height : root->rchild->height) + 1;
    else if(root->lchild && !root->rchild)
        root->height = root->lchild->height + 1;
    else if(!root->lchild && root->rchild)
        root->height = root->rchild->height + 1;
    else
        root->height = 1;
}

int _balance_judge_AVLNode(AVLNode *root) {
    if(!root)   //空树平衡
        return 1;
    else {
        int l_height = root->lchild ? root->lchild->height : 0,
            r_height = root->rchild ? root->rchild->height : 0;
        int balance_factor_abs = l_height > r_height ? l_height - r_height : r_height - l_height;   //计算平衡因子绝对值
        if(balance_factor_abs <= 1)
            return 1;
        else
            return 0;
    }
}

AVLNode *_left_Rotation_AVL(AVLNode *root) {
    AVLNode *new_root = root->rchild;
    root->rchild = root->rchild->lchild;
    new_root->lchild = root;
    _height_update_AVLNode(new_root->lchild);
    _height_update_AVLNode(new_root);
    return new_root;
}

AVLNode *_right_Rotation_AVL(AVLNode *root) {
    AVLNode *new_root = root->lchild;
    root->lchild = root->lchild->rchild;
    new_root->rchild = root;
    _height_update_AVLNode(new_root->rchild);
    _height_update_AVLNode(new_root);
    return new_root;
}

AVLNode *_adjustment_AVL(AVLNode *root) {
    if(_balance_judge_AVLNode(root))
        return root;
    else {
        int l_height = root->lchild ? root->lchild->height : 0,
            r_height = root->rchild ? root->rchild->height : 0;
        AVLNode *new_root = NULL;
        if(l_height > r_height) { //必有左子树
            int L_l_height = root->lchild->lchild ? root->lchild->lchild->height : 0,
                L_r_height = root->lchild->rchild ? root->lchild->rchild->height : 0;
            if(L_l_height < L_r_height) //LR型
                root->lchild = _left_Rotation_AVL(root->lchild);
            new_root = _right_Rotation_AVL(root);
        }
        else {  //必有右子树
            int R_l_height = root->rchild->lchild ? root->rchild->lchild->height : 0,
                R_r_height = root->rchild->rchild ? root->rchild->rchild->height : 0;
            if(R_l_height > R_r_height) //RL型
                root->rchild = _right_Rotation_AVL(root->rchild);
            new_root = _left_Rotation_AVL(root);
        }
        return new_root;
    }
}

AVLNode *insert_AVLNode(AVLNode *root, int key) {
    if(!root)
        return _new_AVLNode(key);
    else if(root->key == key)
        return root;
    else if(root->key > key)
        root->lchild = insert_AVLNode(root->lchild, key);
    else
        root->rchild = insert_AVLNode(root->rchild, key);
    _height_update_AVLNode(root);
    return _adjustment_AVL(root);
}

AVLNode *erase_AVLNode(AVLNode *root, int key) {
    if(!root)
        return NULL;
    else {
        if(root->key > key)
            root->lchild = erase_AVLNode(root->lchild, key);
        else if(root->key < key)
            root->rchild = erase_AVLNode(root->rchild, key);
        else {
            if(root->lchild == NULL || root->rchild == NULL) {
                AVLNode *new_root = root->lchild ? root->lchild : root->rchild;
                free(root);
                root = new_root;
            }
            else {
                AVLNode *pre = root->lchild;
                while(pre->rchild)
                    pre = pre->rchild;
                root->key = pre->key;
                root->lchild = erase_AVLNode(root->lchild, pre->key);
            }
        }
    }
    _height_update_AVLNode(root);
    return _adjustment_AVL(root);
}

int search_AVL(AVLNode *root, int key) {
    if(!root)
        return 0;
    else {
        if(root->key == key)
            return 1;
        else if(root->key > key)
            return search_AVL(root->lchild, key);
        else
            return search_AVL(root->rchild, key);
    }
}