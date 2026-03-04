#ifndef THREAD_BI_TREE_H
#define THREAD_BI_TREE_H
//file: threadBiTree.h (this)

typedef struct threadBiNode {
    int data;
    struct threadBiNode *lchild, *rchild;
    int ltag, rtag;
}threadBiNode, *threadBiTree;

//file: threadBiTree.cpp

/******inorder thread******/
void _thread_in(threadBiTree &T, threadBiNode *&pre);
void create_thread_in(threadBiTree &T);
threadBiNode *first_thread_in(threadBiTree &T);
threadBiNode *next_thread_in(threadBiNode *&p);
void traverse_thread_in(threadBiTree &T, void (*visit)(threadBiNode *&p));
threadBiNode *last_thread_in(threadBiTree &T);
threadBiNode *previous_thread_in(threadBiNode *&p);
void traverse_reverse_thread_in(threadBiTree &T, void (*visit)(threadBiNode *&p));

/******preorder thread******/
void _thread_pre(threadBiTree &T, threadBiNode *&pre);
void create_thread_pre(threadBiTree &T);
threadBiNode *first_thread_pre(threadBiTree &T);
threadBiNode *next_thread_pre(threadBiNode *&p);
void traverse_thread_pre(threadBiTree &T, void (*visit)(threadBiNode *&p));

/******postorder thread******/
void _thread_post(threadBiTree &T, threadBiNode *&pre);
void create_thread_post(threadBiTree &T);

#endif