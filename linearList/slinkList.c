#include <stdlib.h>
#include "slinkList.h"

// can be called only once for a new list. recalling must call Destory_xxx first.
int Init_slinkList(slinkList *L)
{
    if (L)
    {
        L->head = (SLNode *)malloc(sizeof(SLNode));
        if (L->head == NULL)
            return 0;
        L->head->next = NULL;
        L->length = 0;
        return 1;
    }
    return 0;
}

//must call Init_xxx first
int Destroy_slinkList(slinkList *L)
{
    if (L && L->head)
    {
        SLNode *p = L->head, *q = NULL;
        while (p)
        {
            q = p;
            p = p->next;
            free(q);
        }
        L->head = NULL;
        L->length = 0;
        return 1;
    }
    return 0;
}

int GetLength_slinkList(slinkList *L)
{
    if (L)
        return L->length;
    else
        return 0;
}

int GetPos_slinkList(slinkList *L, slinkList_DataType e)
{
    int i = 0;
    if (L && L->head)
    {
        SLNode *p = L->head->next;
        while (p)
        {
            ++i;
            if (p->data == e)
                break;
            p = p->next;
        }
        if (!p)
            i = 0;
    }
    return i;
}

int GetVal_slinkList(slinkList *L, int pos, slinkList_DataType *e)
{
    if (L && L->head && e != NULL && pos > 0 && pos <= L->length)
    {
        SLNode *p = L->head->next;
        int i = 0;
        while (p)
        {
            ++i;
            if (i == pos)
            {
                *e = p->data;
                return 1;
            }
            p = p->next;
        }
    }
    return 0;
}

int Insert_slinkList(slinkList *L, int pos, slinkList_DataType e)
{
    if (L && L->head && pos > 0 && pos <= L->length + 1)
    {
        SLNode *E = (SLNode *)malloc(sizeof(SLNode));
        if (!E)
            return 0;
        E->data = e;
        int i = 0;
        SLNode *prev = L->head;
        while (prev)
        {
            if (i == pos - 1)
                break;
            ++i;
            prev = prev->next;
        }
        if (!prev)
            return 0;
        E->next = prev->next;
        prev->next = E;
        ++(L->length);
        return 1;
    }
    return 0;
}

// must call Init_xxx first before calling this function
int Delete_slinkList(slinkList *L, int pos, slinkList_DataType *e)
{
    if (L && L->head && e != NULL && pos > 0 && pos <= L->length)
    {
        SLNode *prev = L->head, *D = L->head->next;
        int i = 0;
        while (D)
        {
            if (i == pos - 1)
                break;
            ++i;
            prev = prev->next;
            D = D->next;
        }
        if (!D || !prev)
            return 0;
        *e = D->data;
        prev->next = D->next;
        free(D);
        --(L->length);
        return 1;
    }
    return 0;
}

int Traverse_slinkList(slinkList *L, void (*visit)(slinkList_DataType e))
{
    if (L && L->head && visit)
    {
        SLNode *p = L->head->next;
        while (p)
        {
            visit(p->data);
            p = p->next;
        }
        return 1;
    }
    return 0;
}