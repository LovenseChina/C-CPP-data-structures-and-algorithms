#include<stdio.h>
#include<stdlib.h>
#include"sqStack.c"

int main(void) {
    printf("test begining...\n");

    sqStack *s = (sqStack*)malloc(sizeof(sqStack));
    sqStack_DataType topKey;
    Init_sqStack(s, 5);

    if(IsEmpty_sqStack(s))
        printf("stack is empty\n");

    for(int i = 0; i < 5; ++i)
        if(Push_sqStack(s, i)) {
            GetTop_sqStack(s, &topKey);
            printf("pushed key: %d\n", topKey);
        }

    if(IsFull_sqStack(s))
        printf("stack is full\ntry to push\n");
    
    for(int i = 0; i < 5; ++i)
        if(Push_sqStack(s, i)) {
            GetTop_sqStack(s, &topKey);
            printf("pushed key: %d\n", topKey);
        }

    printf("stack size: %d\n", Size_sqStack(s));

    printf("pop all keys\n");
    while(!IsEmpty_sqStack(s)) {
        Pop_sqStack(s, &topKey);
        printf("poped key: %d\n", topKey);
    }
    
    if(Destroy_sqStack(s))
        printf("stack is destroyed\n");
    return 0;
}