#ifndef STATIC_LINK_LIST_H
#define STATIC_LINK_LIST_H
#include "UserDefination.h"

typedef struct STLNode
{
    static_linkList_DataType data;
    int next;
} STLNode;
typedef struct static_linkList
{
    STLNode *list;
    int length;
    int size;
} static_linkList;
int Init_static_linkList(static_linkList *L, int size);
int Destroy_static_linkList(static_linkList *L);
int GetLength_static_linkList(static_linkList *L);
int GetPos_static_linkList(static_linkList *L, static_linkList_DataType e);
int GetVal_static_linkList(static_linkList *L, int pos, static_linkList_DataType *e);
int Insert_static_linkList(static_linkList *L, int pos, static_linkList_DataType e);
int Delete_static_linkList(static_linkList *L, int pos, static_linkList_DataType *e);
int Traverse_static_linkList(static_linkList *L, void (*visit)(static_linkList_DataType e));

#endif