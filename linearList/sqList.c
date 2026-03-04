#include <stdlib.h>
#include "sqList.h"

// can be called only once for a new list. recalling must call Destory_xxx first.
int Init_sqList(sqList *L, int size)
{
    if (L)
    {
        if (size <= 0)
        {
            L->length = L->size = 0;
            return 0;
        }
        L->list = (sqList_DataType *)malloc(sizeof(sqList_DataType) * size);
        if (L->list == NULL)
        {
            L->length = L->size = 0;
            return 0;
        }

        L->size = size;
        L->length = 0;
        return 1;
    }
    return 0;
}

//must call Init_xxx first
int Destroy_sqList(sqList *L)
{
    if (L && L->list)
    {
        free(L->list);
        L->list = NULL;
        L->size = 0;
        L->length = 0;
        return 1;
    }
    return 0;
}

int GetLength_sqList(sqList *L)
{
    if (L && L->list)
        return L->length;
    return 0;
}

int GetPos_sqList(sqList *L, sqList_DataType e)
{
    int i = -1;
    if (L && L->list)
        for (i = L->length - 1; i >= 0; --i)
            if ((L->list)[i] == e)
                break;
    return i + 1;
}

int GetVal_sqList(sqList *L, int pos, sqList_DataType *e)
{
    if (L && L->list && e != NULL && pos > 0 && pos <= L->length)
    {
        *e = L->list[pos - 1];
        return 1;
    }
    return 0;
}

int Insert_sqList(sqList *L, int pos, sqList_DataType e)
{
    if (L && L->list && pos > 0 && pos <= L->length + 1 && L->length < L->size)
    {
        for (int j = L->length; j > pos - 1; --j)
            (L->list)[j] = (L->list)[j - 1];
        (L->list)[pos - 1] = e;
        ++(L->length);
        return 1;
    }
    return 0;
}

// must call Init_xxx first before calling this function
int Delete_sqList(sqList *L, int pos, sqList_DataType *e)
{
    if (L && L->list && e != NULL && pos > 0 && pos <= L->length)
    {
        *e = (L->list)[pos - 1];
        for (int i = pos - 1; i < L->length - 1; ++i)
            (L->list)[i] = (L->list)[i + 1];
        --(L->length);
        return 1;
    }
    return 0;
}

int Traverse_sqList(sqList *L, void (*visit)(sqList_DataType e))
{
    if (L && L->list && visit)
    {
        for (int i = 0; i < L->length; ++i)
            visit((L->list)[i]);
        return 1;
    }
    return 0;
}