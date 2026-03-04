#include <stdlib.h>
#include "dlinkList.h"

// can be called only once for a new list. recalling must call Destory_xxx first.
int Init_dlinkList(dlinkList *L)
{
    if (L)
    {
        L->head = (DLNode *)malloc(sizeof(DLNode));
        if (!(L->head))
            return 0;
        L->head->next = NULL;
        L->head->prior = NULL;
        L->tail = L->head;
        L->length = 0;
        return 1;
    }
    return 0;
}

//must call Init_xxx first
int Destroy_dlinkList(dlinkList *L)
{
    if (L)
    {
        DLNode *p = NULL, *q = L->head;
        while (q)
        {
            p = q;
            q = q->next;
            free(p);
        }
        L->head = L->tail = NULL;
        L->length = 0;
        return 1;
    }
    return 0;
}

int GetLength_dlinkList(dlinkList *L)
{
    if (L)
        return L->length;
    else
        return 0;
}

int GetPos_dlinkList(dlinkList *L, dlinkList_DataType e)
{
    int i = 0;
    if (L)
    {
        DLNode *p = L->head->next;
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

int GetVal_dlinkList(dlinkList *L, int pos, dlinkList_DataType *e)
{
    if (L && L->head && e != NULL && pos > 0 && pos <= L->length)
    {
        int i = 0;
        DLNode *p = L->head->next;
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

int Insert_dlinkList(dlinkList *L, int pos, dlinkList_DataType e)
{
    if (L && L->head && pos > 0 && pos <= L->length + 1)
    {
        DLNode *E = (DLNode *)malloc(sizeof(DLNode));
        if (!E)
            return 0;
        E->data = e;
        if (pos == L->length + 1)
        {
            E->next = NULL;
            E->prior = L->tail;
            L->tail->next = E;
            L->tail = E;
        }
        else
        {
            int i = 0;
            DLNode *p = L->head->next;
            while (p)
            {
                ++i;
                if (i == pos)
                    break;
                p = p->next;
            }
            E->next = p;
            E->prior = p->prior;
            E->prior->next = E;
            E->next->prior = E;
        }
        ++(L->length);
        return 1;
    }
    return 0;
}

// must call Init_xxx first before calling this function
int Delete_dlinkList(dlinkList *L, int pos, dlinkList_DataType *e)
{
    if (L && L->head && e != NULL && pos > 0 && pos <= L->length)
    {
        DLNode *D = NULL;
        if (pos == L->length)
        {
            *e = L->tail->data;
            D = L->tail;
            L->tail = L->tail->prior;
            L->tail->next = NULL;
        }
        else
        {
            int i = 0;
            D = L->head->next;
            while (D)
            {
                ++i;
                if (i == pos)
                    break;
                D = D->next;
            }
            D->prior->next = D->next;
            D->next->prior = D->prior;
        }
        free(D);
        --(L->length);
        return 1;
    }
    return 0;
}

int Traverse_dlinkList(dlinkList *L, void (*visit)(dlinkList_DataType e))
{
    if (L && L->head && visit)
    {
        DLNode *p = L->head->next;
        while (p)
        {
            visit(p->data);
            p = p->next;
        }
        return 1;
    }
    return 0;
}

int TraverseReverse_dlinkList(dlinkList *L, void (*visit)(dlinkList_DataType e))
{
    if (L && L->head && visit)
    {
        DLNode *p = L->tail;
        while (p != L->head)
        {
            visit(p->data);
            p = p->prior;
        }
        return 1;
    }
    return 0;
}