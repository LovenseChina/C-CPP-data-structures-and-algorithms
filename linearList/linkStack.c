#include <stdio.h>
#include "linkStack.h"

int Init_linkStack(linkStack *s)
{
    if (!s)
        return 0;
    s->top_prev = (LSTNode *)malloc(sizeof(LSTNode));
    if (!(s->top_prev))
        return 0;
    s->top_prev->next = NULL;
    s->length = 0;
    return 1;
}

int Destroy_linkStack(linkStack *s)
{
    if (!s || !(s->top_prev))
        return 0;
    LSTNode *p = NULL;
    while (s->top_prev)
    {
        p = s->top_prev;
        s->top_prev = s->top_prev->next;
        free(p);
    }
    s->length = 0;
    return 1;
}

int IsEmpty_linkStack(linkStack *s)
{
    if (!s || !(s->top_prev))
        return 1;
    return 0 == s->length;
}

int GetTop_linkStack(linkStack *s, linkStack_DataType *e)
{
    if (s && s->top_prev && s->top_prev->next)
    {
        *e = s->top_prev->next->data;
        return 1;
    }
    return 0;
}

int Push_linkStack(linkStack *s, linkStack_DataType e)
{
    if (!s || !(s->top_prev))
        return 0;
    LSTNode *p = (LSTNode *)malloc(sizeof(LSTNode));
    if (!p)
        return 0;
    p->data = e;
    p->next = s->top_prev->next;
    s->top_prev->next = p;
    ++(s->length);
    return 1;
}

int Pop_linkStack(linkStack *s, linkStack_DataType *e)
{
    if (!s || !(s->top_prev) || !(s->top_prev->next))
        return 0;
    LSTNode *p = s->top_prev->next;
    *e = p->data;
    s->top_prev->next = p->next;
    free(p);
    --(s->length);
    return 1;
}