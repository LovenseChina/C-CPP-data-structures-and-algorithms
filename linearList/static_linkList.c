#include <stdlib.h>
#include "static_linkList.h"
// reference:
// https://cloud.tencent.com/developer/article/1010387

// can be called only once for a new list. recalling must call Destory_xxx first.
int Init_static_linkList(static_linkList *L, int size)
{
    if (L)
    {
        if (size <= 0)
        {
            L->length = L->size = 0;
            return 0;
        }
        L->list = (STLNode *)malloc(sizeof(STLNode) * (size + 2));
        if (L->list == NULL)
        {
            L->length = L->size = 0;
            return 0;
        }
        L->size = size;
        L->length = 0;
        (L->list)[0].next = -1;
        (L->list)[L->size + 1].next = 1;
        for (int i = 1; i < L->size; ++i)
            (L->list)[i].next = i + 1;
        (L->list)[L->size].next = -1;
        return 1;
    }
    return 0;
}

//must call Init_xxx first
int Destroy_static_linkList(static_linkList *L)
{
    if (L && L->list)
    {
        free(L->list);
        L->list = NULL;
        L->length = L->size = 0;
        return 1;
    }
    return 0;
}

int GetLength_static_linkList(static_linkList *L)
{
    if (L && L->list)
        return L->length;
    return 0;
}

int GetPos_static_linkList(static_linkList *L, static_linkList_DataType e)
{
    int i = 0;
    if (L && L->list)
    {
        int p = (L->list)[0].next;
        while (p != -1)
        {
            ++i;
            if ((L->list)[p].data == e)
                break;
            p = (L->list)[p].next;
        }
        if (p == -1)
            i = 0;
    }
    return i;
}

int GetVal_static_linkList(static_linkList *L, int pos, static_linkList_DataType *e)
{
    if (L && L->list && e != NULL && pos > 0 && pos <= L->length)
    {
        int i = 0;
        int p = (L->list)[0].next;
        while (p != -1)
        {
            ++i;
            if (i == pos)
                break;
            p = (L->list)[p].next;
        }
        if (p != -1)
        {
            *e = (L->list)[p].data;
            return 1;
        }
    }
    return 0;
}

int Insert_static_linkList(static_linkList *L, int pos, static_linkList_DataType e)
{
    if (L && L->list && pos > 0 && pos <= L->length + 1 && (L->list)[L->size + 1].next != -1) // or use 'L->length < L->size' replace '(L->list)[L->size + 1].next != -1'
    {
        int E = (L->list)[L->size + 1].next;
        (L->list)[L->size + 1].next = (L->list)[(L->list)[L->size + 1].next].next; // Allocate first block on vacancy list
        (L->list)[E].data = e;

        int i = 0;
        int p = 0;
        while (p != -1)
        {
            if (i == pos - 1)
                break;
            ++i;
            p = (L->list)[p].next;
        }
        // if(p == -1)
        //     return 0;
        (L->list)[E].next = (L->list)[i].next;
        (L->list)[i].next = E;
        ++(L->length);
        return 1;
    }
    return 0;
}

// must call Init_xxx first before calling this function
int Delete_static_linkList(static_linkList *L, int pos, static_linkList_DataType *e)
{
    if (L && L->list && e != NULL && pos > 0 && pos <= L->length)
    {
        int D = -1;
        int i = 0;
        int p = 0;
        while (p != -1)
        {
            if (i == pos - 1)
                break;
            ++i;
            p = (L->list)[p].next;
        }
        // if(p == -1 || (L->list)[p].next == - 1)
        //     return 0;
        D = (L->list)[p].next;
        (L->list)[p].next = (L->list)[(L->list)[p].next].next;
        *e = (L->list)[D].data;
        (L->list)[D].next = (L->list)[L->size + 1].next;
        (L->list)[L->size + 1].next = D;
        --(L->length);
        return 1;
    }
    return 0;
}

int Traverse_static_linkList(static_linkList *L, void (*visit)(static_linkList_DataType e))
{
    if (L && L->list && visit)
    {
        int p = (L->list)[0].next;
        while (p != -1)
        {
            visit((L->list)[p].data);
            p = (L->list)[p].next;
        }
        return 1;
    }
    return 0;
}