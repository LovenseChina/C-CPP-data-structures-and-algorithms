#include<stdio.h>
#include"sqQueue.c"

int main() {
    printf("test begining...\n");

    sqQueue *q = (sqQueue*)malloc(sizeof(sqQueue));
    if(!q)
        return -1;
    Init_sqQueue(q, 10);

    for(int i = 0; i < 15; ++i)
        if(EnQ_sqQueue(q, i))
            printf("enqueue key: %d\n", i);
        else
            printf("failed enqueue key: %d\n", i);
    printf("%d keys in queue\n", Count_sqQueue(q));

    sqQueue_DataType d;
    for(int i = 0; i < 5; ++i)
        if(DeQ_sqQueue(q, &d))
            printf("dequeue key: %d\n", d);
        else
            printf("failed dequeue key\n");
    printf("%d keys in queue\n", Count_sqQueue(q));

    for(int i = 0; i < 15; ++i)
        if(EnQ_sqQueue(q, i))
            printf("enqueue key: %d\n", i);
        else
            printf("failed enqueue key: %d\n", i);
    printf("%d keys in queue\n", Count_sqQueue(q));

    while(DeQ_sqQueue(q, &d));
    if(Count_sqQueue(q) == 0)
        printf("all keys are dequeued\n");
        
    return 0;
}