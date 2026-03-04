#include<stdio.h>
#include"linkQueue.c"

int main() {
    printf("test begining...\n");

    linkQueue *q = (linkQueue*)malloc(sizeof(linkQueue));
    if(!q)
        return -1;
    Init_linkQueue(q);

    for(int i = 0; i < 15; ++i)
        if(EnQ_linkQueue(q, i))
            printf("enqueue key: %d\n", i);
        else
            printf("failed enqueue key: %d\n", i);

    linkQueue_DataType d;
    for(int i = 0; i < 5; ++i)
        if(DeQ_linkQueue(q, &d))
            printf("dequeue key: %d\n", d);
        else
            printf("failed dequeue key\n");

    for(int i = 0; i < 15; ++i)
        if(EnQ_linkQueue(q, i))
            printf("enqueue key: %d\n", i);
        else
            printf("failed enqueue key: %d\n", i);

    while(DeQ_linkQueue(q, &d));
    if(IsEmpty_linkQueue(q) != QUEUE_INVALID_ERROR && IsEmpty_linkQueue(q) == 1)
        printf("all keys are dequeued\n");

    free(q);
    q = NULL;
        
    return 0;
}