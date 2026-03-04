#ifndef LINK_STACK_H
#define LINK_STACK_H
#include "UserDefination.h"

typedef struct LSTNode
{
    linkStack_DataType data;
    struct LSTNode *next;
} LSTNode;
typedef struct linkStack
{
    LSTNode *top_prev;
    int length;
} linkStack;
int Init_linkStack(linkStack *s);
int Destroy_linkStack(linkStack *s);
int IsEmpty_linkStack(linkStack *s);
int GetTop_linkStack(linkStack *s, linkStack_DataType *e);
int Push_linkStack(linkStack *s, linkStack_DataType e);
int Pop_linkStack(linkStack *s, linkStack_DataType *e);

#endif