#ifndef RECURSIVE_ALGO_H
#define RECURSIVE_ALGO_H
/*下划线开头函数为内部函数，非下划线开头者为接口函数*/

/* BST */
typedef struct BSTNode {
    struct BSTNode *lchild, *rchild;
    int key;
} BSTNode;

BSTNode *_new_BSTNode(int key);
BSTNode *insert_BSTNode(BSTNode *root, int key);
BSTNode *erase_BSTNode(BSTNode *root, int key);
int search_BST(BSTNode *root, int key);

/* AVL */
typedef struct AVLNode {
    struct AVLNode *lchild, *rchild;
    int key, height;
}AVLNode;

AVLNode *_new_AVLNode(int key);
void _height_update_AVLNode(AVLNode *root);
int _balance_judge_AVLNode(AVLNode *root);
AVLNode *_left_Rotation_AVL(AVLNode *root);
AVLNode *_right_Rotation_AVL(AVLNode *root);
AVLNode *_adjustment_AVL(AVLNode *root);
AVLNode *insert_AVLNode(AVLNode *root, int key);
AVLNode *erase_AVLNode(AVLNode *root, int key);
int search_AVL(AVLNode *root, int key);

#endif