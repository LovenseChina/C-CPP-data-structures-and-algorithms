#include <stdio.h>
#include "static_linkList.c"

void visit(static_linkList_DataType e)
{
    printf("%d  ", e);
}

int main()
{
    printf("test begining...\n");
    static_linkList *L = (static_linkList *)malloc(sizeof(static_linkList));
    if (!L)
        return -1;
    Init_static_linkList(L, 10); // can be called only once for a new variable. recalling must call Destory_xxx first.
    static_linkList_DataType e;
    int pos;

    for (int i = 1; i <= 10; ++i)
        if (Insert_static_linkList(L, i, (static_linkList_DataType)i) == 1)
        {
            GetVal_static_linkList(L, i, &e);
            pos = GetPos_static_linkList(L, e);
            printf("key %d is Inserted in pos %d\n", e, pos);
        }
        else
            printf("Failed: key %d isn't Inserted in pos %d\n", e, pos);
    printf("List Length: %d\n", GetLength_static_linkList(L));

    for (int i = 10; i > 0; --i)
    {
        if (Delete_static_linkList(L, i, &e) == 1)
            printf("key %d in pos %d has deleted\n", e, i);
        else
            printf("Failed: key %d in pos %d has not deleted\n", e, i);
    }

    for (int i = 1; i <= 10; ++i)
        if (Insert_static_linkList(L, i, (static_linkList_DataType)i) == 1)
        {
            GetVal_static_linkList(L, i, &e);
            pos = GetPos_static_linkList(L, e);
            printf("key %d is Inserted in pos %d\n", e, pos);
        }
        else
            printf("Failed: key %d isn't Inserted in pos %d\n", e, pos);
    printf("List Length: %d\n", GetLength_static_linkList(L));

    for (int i = 10; i > 0; i /= 2)
    {
        if (Delete_static_linkList(L, i, &e) == 1)
            printf("key %d in pos %d has deleted\n", e, i);
        else
            printf("Failed: key %d in pos %d has not deleted\n", e, i);
    }
    printf("List Length: %d\n", GetLength_static_linkList(L));

    if (Insert_static_linkList(L, 8, 8) == 1)
        printf("Insertion can be done in pos 8\n");
    else
        printf("Insertion cannot be done in pos 8\n");
    if (Insert_static_linkList(L, 7, 15) == 1)
        printf("Insertion can be done in pos 7\n");
    else
        printf("Insertion cannot be done in pos 7\n");

    printf("traverse list:\n");
    Traverse_static_linkList(L, visit);
    printf("\n");

    if (Destroy_static_linkList(L) == 1)
        printf("List had destoryed\n");
    if (L)
        free(L);
    return 0;
}