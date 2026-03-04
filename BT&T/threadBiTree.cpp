#include "threadBiTree.h"
/******inorder thread******/
// cannot be called by user
void _thread_in(threadBiTree &T, threadBiNode *&pre)
{
    if (!T)
        return;

    _thread_in(T->lchild, pre);
    if (pre && pre->rchild == nullptr)
    {
        pre->rtag = 1;
        pre->rchild = T;
    }
    if (T->lchild == nullptr)
    {
        T->ltag = 1;
        T->lchild = pre;
    }
    pre = T;
    _thread_in(T->rchild, pre);
}

// assume that the tags of tree have been initialize by zero
void create_thread_in(threadBiTree &T)
{
    if (!T)
        return;
    threadBiNode *pre = nullptr;
    _thread_in(T, pre);
    if (pre)
    {
        pre->rtag = 1;
        pre->rchild = nullptr;
    }
}

// assume that the data structure is validate
threadBiNode *first_thread_in(threadBiTree &T)
{
    if (!T)
        return nullptr;
    threadBiNode *p = T;
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}

// assume that the data structure is validate
threadBiNode *next_thread_in(threadBiNode *&p)
{
    if (!p)
        return nullptr;
    if (p->rtag == 1)
        return p->rchild;
    else
        return first_thread_in(p->rchild);
}

// assume that the data structure is validate
void traverse_thread_in(threadBiTree &T, void (*visit)(threadBiNode *&p))
{
    for (threadBiNode *p = first_thread_in(T); p != nullptr; p = next_thread_in(p))
        visit(p);
}

// assume that the data structure is validate
threadBiNode *last_thread_in(threadBiTree &T)
{
    if (!T)
        return nullptr;
    threadBiNode *p = T;
    while (p->rtag == 0)
        p = p->rchild;
    return p;
}

// assume that the data structure is validate
threadBiNode *previous_thread_in(threadBiNode *&p)
{
    if (!p)
        return nullptr;
    if (p->ltag == 1)
        return p->lchild;
    else
        return last_thread_in(p->lchild);
}

// assume that the data structure is validate
void traverse_reverse_thread_in(threadBiTree &T, void (*visit)(threadBiNode *&p))
{
    for (threadBiNode *p = last_thread_in(T); p != nullptr; p = previous_thread_in(p))
        visit(p);
}

/******preorder thread******/
// cannot be called by user
void _thread_pre(threadBiTree &T, threadBiNode *&pre)
{
    if (!T)
        return;
    if (pre && pre->rchild == nullptr)
    {
        pre->rtag = 1;
        pre->rchild = T;
    }
    if (T->lchild == nullptr)
    {
        T->ltag = 1;
        T->lchild = pre;
    }
    //T->rtag = T->rchild == nullptr ? 1 : 0; // 可以减少递归深度的优化

    pre = T;
    if (T->ltag == 0) // 若已经线索化再次进入则会因为指针不空再次被线索化所以当未被线索化才递归执行线索化
        _thread_pre(T->lchild, pre);
    if (T->rtag == 0)
        _thread_pre(T->rchild, pre);
}

// assume that the tags of tree have been initialize by zero
void create_thread_pre(threadBiTree &T)
{
    if (!T)
        return;
    threadBiNode *pre = nullptr;
    _thread_pre(T, pre);
    if (pre && pre->rchild == nullptr)
    {
        pre->rtag = 1;
        pre->rchild = nullptr;
    }
}

// assume that the data structure is validate 
threadBiNode *first_thread_pre(threadBiTree &T) {
/*    if(!T)
        return nullptr;
    else
        return T;
*/
    return T;
}

// assume that the data structure is validate 
threadBiNode *next_thread_pre(threadBiNode *&p) {
    if(!p)
        return nullptr;
    threadBiNode *q = p;
    if(q->ltag == 0)
        return q->lchild;
    else
        return q->rchild;
}

// assume that the data structure is validate 
void traverse_thread_pre(threadBiTree &T, void (*visit)(threadBiNode *&p)) {
    for(threadBiNode *p = first_thread_pre(T); p != nullptr; p = next_thread_pre(p))
        visit(p);
}

/******postorder thread******/
// cannot be called by user
void _thread_post(threadBiTree &T, threadBiNode *&pre)
{
    if (!T)
        return;
    _thread_post(T->lchild, pre);
    _thread_post(T->rchild, pre);
    if (T->lchild == nullptr)
    {
        T->ltag = 1;
        T->lchild = pre;
    }
    if (pre && pre->rchild == nullptr)
    {
        pre->rtag = 1;
        pre->rchild = T;
    }
    pre = T;
}

// assume that the tags of tree have been initialize by zero
void create_thread_post(threadBiTree &T)
{
    if (!T)
        return;
    threadBiNode *pre = nullptr;
    _thread_post(T, pre);
    if (pre && pre->rchild == nullptr)
    {
        pre->rtag = 1;
    }
}