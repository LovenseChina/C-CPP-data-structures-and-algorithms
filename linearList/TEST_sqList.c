#include <stdio.h>
#include "sqList.c"

void visit(sqList_DataType e)
{
    printf("%d  ", e);
}

int main()
{
    printf("test begining...\n");
    sqList *L = (sqList *)malloc(sizeof(sqList));
    if (!L)
        return -1;
    Init_sqList(L, 10); // can be called only once for a new variable. recalling must call Destory_xxx first.
    sqList_DataType e;
    int pos;

    for (int i = 1; i <= 10; ++i)
        if (Insert_sqList(L, i, (sqList_DataType)i) == 1)
        {
            GetVal_sqList(L, i, &e);
            pos = GetPos_sqList(L, e);
            printf("key %d is Inserted in pos %d\n", e, pos);
        }
        else
            printf("Failed: key %d isn't Inserted in pos %d\n", e, pos);
    printf("List Length: %d\n", GetLength_sqList(L));

    for (int i = 10; i > 0; --i)
    {
        if (Delete_sqList(L, i, &e) == 1)
            printf("key %d in pos %d has deleted\n", e, i);
        else
            printf("Failed: key %d in pos %d has not deleted\n", e, i);
    }

    for (int i = 1; i <= 10; ++i)
        if (Insert_sqList(L, i, (sqList_DataType)i) == 1)
        {
            GetVal_sqList(L, i, &e);
            pos = GetPos_sqList(L, e);
            printf("key %d is Inserted in pos %d\n", e, pos);
        }
        else
            printf("Failed: key %d isn't Inserted in pos %d\n", e, pos);
    printf("List Length: %d\n", GetLength_sqList(L));

    for (int i = 10; i > 0; i /= 2)
    {
        if (Delete_sqList(L, i, &e) == 1)
            printf("key %d in pos %d has deleted\n", e, i);
        else
            printf("Failed: key %d in pos %d has not deleted\n", e, i);
    }
    printf("List Length: %d\n", GetLength_sqList(L));

    if (Insert_sqList(L, 8, 8) == 1)
        printf("Insertion can be done in pos 8\n");
    else
        printf("Insertion cannot be done in pos 8\n");
    if (Insert_sqList(L, 7, 15) == 1)
        printf("Insertion can be done in pos 7\n");
    else
        printf("Insertion cannot be done in pos 7\n");

    printf("traverse list:\n");
    Traverse_sqList(L, visit);
    printf("\n");

    if (Destroy_sqList(L) == 1)
        printf("List had destoryed\n");
    if (L)
        free(L);
    return 0;
}