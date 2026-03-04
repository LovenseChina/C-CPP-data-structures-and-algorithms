#ifndef SQ_STACK_H
#define SQ_STACK_H
#include "UserDefination.h"

typedef struct sqStack
{
    sqList_DataType *stack;
    int top;
    int size;
} sqStack;
int Init_sqStack(sqStack *s, int size);
int Destroy_sqStack(sqStack *s);
int Size_sqStack(sqStack *s);
int GetTop_sqStack(sqStack *s, sqStack_DataType *e);
int IsFull_sqStack(sqStack *s);
int IsEmpty_sqStack(sqStack *s);
int Pop_sqStack(sqStack *s, sqStack_DataType *e);
int Push_sqStack(sqStack *s, sqStack_DataType e);
int _Extend_sqStack(sqStack *s);

#endif