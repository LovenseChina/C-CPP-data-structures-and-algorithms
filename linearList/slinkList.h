#ifndef SLINK_LIST_H
#define SLINK_LIST_H
#include "UserDefination.h"

typedef struct SLNode
{
    slinkList_DataType data;
    struct SLNode *next;
} SLNode;
typedef struct slinkList
{
    SLNode *head;
    int length;
} slinkList;
int Init_slinkList(slinkList *L);
int Destroy_slinkList(slinkList *L);
int GetLength_slinkList(slinkList *L);
int GetPos_slinkList(slinkList *L, slinkList_DataType e);
int GetVal_slinkList(slinkList *L, int pos, slinkList_DataType *e);
int Insert_slinkList(slinkList *L, int pos, slinkList_DataType e);
int Delete_slinkList(slinkList *L, int pos, slinkList_DataType *e);
int Traverse_slinkList(slinkList *L, void (*visit)(slinkList_DataType e));

#endif