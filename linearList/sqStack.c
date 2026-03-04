#include <stdlib.h>
#include <limits.h>
#include "sqStack.h"
// Caution: this data structure does not support deep copy

// can be called only once for a new stack. recalling must call Destory_xxx first.
int Init_sqStack(sqStack *s, int size)
{
    if (s && size > 0)
    {
        s->stack = (sqStack_DataType *)malloc(sizeof(sqStack_DataType) * size);
        if (s->stack == NULL)
        {
            s->size = 0;
            s->top = -1;
            return 0;
        }
        s->size = size;
        s->top = -1;
        return 1;
    }
    return 0;
}

// must call Init_xxx first
int Destroy_sqStack(sqStack *s)
{
    if (s && s->stack)
    {
        free(s->stack);
        s->stack = NULL;
        s->size = 0;
        s->top = -1;
        return 1;
    }
    return 0;
}

int Size_sqStack(sqStack *s)
{
    if (s && s->stack)
        return s->size;
    return 0;
}

int GetTop_sqStack(sqStack *s, sqStack_DataType *e)
{
    if (s && s->top > -1)
    {
        *e = (s->stack)[s->top];
        return 1;
    }
    return 0;
}

// this function can only called when s is not NULL
int IsFull_sqStack(sqStack *s)
{
    if (s && s->top == s->size - 1)
        return 1;
    return 0;
}

// this function can only called when s is not NULL
int IsEmpty_sqStack(sqStack *s)
{
    if (s && s->top <= -1)
        return 1;
    return 0;
}

int Pop_sqStack(sqStack *s, sqStack_DataType *e)
{
    if (s && s->top > -1)
    {
        *e = (s->stack)[(s->top)--];
        return 1;
    }
    return 0;
}

int Push_sqStack(sqStack *s, sqStack_DataType e)
{
    if (s && s->stack)
    {
        int extOK = 1;
        if (s->top >= s->size - 1)
            extOK = _Extend_sqStack(s);
        if (extOK == 0)
            return 0;
        (s->stack)[++(s->top)] = e;
        return 1;
    }
    return 0;
}

// NOT a user function
int _Extend_sqStack(sqStack *s)
{
    if (s && s->stack && s->top == s->size - 1 && s->size < INT_MAX / 2)
    {
        sqStack_DataType *ext = (sqStack_DataType *)realloc(s->stack, sizeof(sqStack_DataType) * s->size * 2);
        if (ext == NULL)
            return 0;
        // for (int i = s->top; i > -1; --i)
        //     ext[i] = (s->stack)[i];
        // sqStack_DataType *del = s->stack;
        s->stack = ext;
        s->size *= 2;
        // free(del);
        return 1;
    }
    return 0;
}