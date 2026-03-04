#include <stdio.h>
#include "BiTree.h"
#define MAX_SIZE_TRAVERSE_STACK 100

void visit(const BiNode *p)
{
    printf("%d  ", p->data);
}

void preorder(BiTree *T, void (*visit)(const BiNode *p))
{
    if (!(T->root))
        return;
    BiNode *stack[MAX_SIZE_TRAVERSE_STACK];
    int top = -1;
    stack[++top] = T->root;
    while (top > -1)
    {
        BiNode *p = stack[top--];
        visit(p);
        if (p->rchild)
            stack[++top] = p->rchild;
        if (p->lchild)
            stack[++top] = p->lchild;
    }
}

void inorder(BiTree *T, void (*visit)(const BiNode *p))
{
    BiNode *stack[MAX_SIZE_TRAVERSE_STACK];
    int top = -1;
    BiNode *current = T->root;
    while (top > -1 || current)
    {
        while (current)
        {
            stack[++top] = current;
            current = current->lchild;
        }
        current = stack[top--];
        visit(current);
        current = current->rchild;
    }
}

void posorder(BiTree *T, void (*visit)(const BiNode *p))
{
    BiNode *stack[MAX_SIZE_TRAVERSE_STACK];
    int top = -1;
    BiNode *current = T->root;
    BiNode *last_visited = NULL;
    while (top > -1 || current)
    {
        while (current) //初始按中序方式一路向左入栈因为根不是先访问
        {
            stack[++top] = current;
            current = current->lchild;
        }
        current = stack[top];   //不出栈可能未到到访问时机
        if (current->rchild && last_visited != current->rchild) //有右子树且未被访问转向右子树
            current = current->rchild;
        else
        {
            visit(current);
            last_visited = current; // 后序遍历下某个节点的前驱在当前节点的右子树存在时必然为右孩子因而有if中判断last_visited
            --top;
            current = NULL; // 防止进入开头while循环重复入栈被访问
        }
    }
}