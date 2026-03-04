#ifndef SQ_LIST_H
#define SQ_LIST_H
#include "UserDefination.h"

typedef struct sqList
{
    sqList_DataType *list;
    int length;
    int size;
} sqList;
int Init_sqList(sqList *L, int size);
int Destroy_sqList(sqList *L);
int GetLength_sqList(sqList *L);
int GetPos_sqList(sqList *L, sqList_DataType e);
int GetVal_sqList(sqList *L, int pos, sqList_DataType *e);
int Insert_sqList(sqList *L, int pos, sqList_DataType e);
int Delete_sqList(sqList *L, int pos, sqList_DataType *e);
int Traverse_sqList(sqList *L, void (*visit)(sqList_DataType e));

#endif