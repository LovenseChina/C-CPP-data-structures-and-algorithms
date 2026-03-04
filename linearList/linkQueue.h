#ifndef LINK_QUEUE_H
#define LINK_QUEUE_H
#include "UserDefination.h"
#define QUEUE_INVALID_ERROR -1

typedef struct LQUNode
{
    linkQueue_DataType data;
    struct LQUNode *next;
} LQUNode;
typedef struct linkQueue
{
    LQUNode *front;
    LQUNode *rear;
    int length;
} linkQueue;
int Init_linkQueue(linkQueue *q);
int Destroy_linkQueue(linkQueue *q);
int IsEmpty_linkQueue(linkQueue *q);
int EnQ_linkQueue(linkQueue *q, linkQueue_DataType e);
int DeQ_linkQueue(linkQueue *q, linkQueue_DataType *e);

#endif