#include <stdlib.h>
#include <limits.h>
#include "sqQueue.h"
// Caution: this data structure does not support deep copy

// can be called only once for a new stack. recalling must call Destory_xxx first.
int Init_sqQueue(sqQueue *q, int size)
{
    if (!q || size <= 0)
        return 0;
    q->queue = (sqQueue_DataType *)malloc(sizeof(sqQueue_DataType) * (size + 1));
    if (!(q->queue))
        return 0;
    q->rear = q->front = 0;
    q->size = size;
    return 1;
}

// must call Init_xxx first
int Destroy(sqQueue *q)
{
    if (!q || !(q->queue))
        return 0;
    free(q->queue);
    q->queue = NULL;
    q->rear = q->front = q->size = 0;
    return 1;
}

int Size_sqQueue(sqQueue *q)
{
    if (!q || !(q->queue))
        return 0;
    return q->size;
}

int Count_sqQueue(sqQueue *q) {
    if(!q || !(q->queue))
        return 0;
    return (q->rear - q->front + q->size + 1) % (q->size + 1);
}

//must a valid sqQueue pointer
int _IsFull_sqQueue(sqQueue *q)
{
    return q->front == (q->rear + 1) % (q->size + 1);
}

//must a valid sqQueue pointer
int _IsEmpty_sqQueue(sqQueue *q)
{
    return q->front == q->rear;
}

int EnQ_sqQueue(sqQueue *q, sqQueue_DataType e)
{
    if (!q || !(q->queue) || _IsFull_sqQueue(q))
        return 0;
    (q->queue)[q->rear] = e;
    q->rear = (q->rear + 1) % (q->size + 1);
    return 1;
}

int DeQ_sqQueue(sqQueue *q, sqQueue_DataType *e)
{
    if (!q || !(q->queue) || _IsEmpty_sqQueue(q))
        return 0;
    *e = (q->queue)[q->front];
    q->front = (q->front + 1) % (q->size + 1);
    return 1;
}