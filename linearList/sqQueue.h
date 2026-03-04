#ifndef SQ_QUEUE_H
#define SQ_QUEUE_H
#include"UserDefination.h"

typedef struct sqQueue
{
    sqQueue_DataType *queue;
    int rear;
    int front;
    int size;
}sqQueue;
int Init_sqQueue(sqQueue *q, int size);
int Destroy(sqQueue *q);
int Size_sqQueue(sqQueue *q);
int Count_sqQueue(sqQueue *q);
int _IsFull_sqQueue(sqQueue *q);
int _IsEmpty_sqQueue(sqQueue *q);
int EnQ_sqQueue(sqQueue *q, sqQueue_DataType e);
int DeQ_sqQueue(sqQueue *q, sqQueue_DataType *e);

#endif