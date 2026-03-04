#ifndef DLINK_LIST_H
#define DLINK_LIST_H
#include "UserDefination.h"

typedef struct DLNode
{
    dlinkList_DataType data;
    struct DLNode *next;
    struct DLNode *prior;
} DLNode;
typedef struct dlinkList
{
    DLNode *head;
    DLNode *tail;
    int length;
} dlinkList;
int Init_dlinkList(dlinkList *L);
int Destroy_dlinkList(dlinkList *L);
int GetLength_dlinkList(dlinkList *L);
int GetPos_dlinkList(dlinkList *L, dlinkList_DataType e);
int GetVal_dlinkList(dlinkList *L, int pos, dlinkList_DataType *e);
int Insert_dlinkList(dlinkList *L, int pos, dlinkList_DataType e);
int Delete_dlinkList(dlinkList *L, int pos, dlinkList_DataType *e);
int Traverse_dlinkList(dlinkList *L, void (*visit)(dlinkList_DataType e));
int TraverseReverse_dlinkList(dlinkList *L, void (*visit)(dlinkList_DataType e));

#endif