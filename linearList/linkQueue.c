#include <stdlib.h>
#include "linkQueue.h"

// can be called only once for a new queue. recalling must call Destory_xxx first.
int Init_linkQueue(linkQueue *q)
{
    if (!q)
        return 0;
    q->rear = q->front = NULL;
    q->length = 0;
    return 1;
}

//must call Init_xxx first
int Destroy_linkQueue(linkQueue *q)
{
    if (!q)
        return 0;
    LQUNode *p = NULL;
    while (q->front)
    {
        p = q->front;
        q->front = q->front->next;
        free(p);
    }
    q->length = 0;
    q->rear = q->front = NULL;
    return 1;
}

//must check error code first
int IsEmpty_linkQueue(linkQueue *q)
{
    if (!q)
        return QUEUE_INVALID_ERROR;
    return 0 == q->length;
}

int EnQ_linkQueue(linkQueue *q, linkQueue_DataType e)
{
    if (!q)
        return 0;
    LQUNode *p = (LQUNode *)malloc(sizeof(LQUNode));
    if (!p)
        return 0;
    p->data = e;
    p->next = NULL;
    if (0 == q->length)
        q->rear = q->front = p;
    else
    {
        q->rear->next = p;
        q->rear = p;
    }
    ++(q->length);
    return 1;
}

int DeQ_linkQueue(linkQueue *q, linkQueue_DataType *e)
{
    if (!q || 0 == q->length)
        return 0;
    LQUNode *p = q->front;
    if (e)
        *e = p->data;
    if (q->rear == q->front)
        q->rear = q->front = NULL;
    else
        q->front = q->front->next;
    free(p);
    --(q->length);
    return 1;
}