#include<stdio.h>
#include<stdlib.h>
#include"linkStack.c"

int main(void) {
    printf("test begining...\n");

    linkStack *s = (linkStack*)malloc(sizeof(linkStack));
    if(!s)
        return -1;
    linkStack_DataType topKey;
    Init_linkStack(s);

    if(IsEmpty_linkStack(s))
        printf("stack is empty\n");

    for(int i = 0; i < 5; ++i)
        if(Push_linkStack(s, i)) {
            GetTop_linkStack(s, &topKey);
            printf("pushed key: %d\n", topKey);
        }
    
    for(int i = 0; i < 5; ++i)
        if(Push_linkStack(s, i)) {
            GetTop_linkStack(s, &topKey);
            printf("pushed key: %d\n", topKey);
        }

    printf("pop all keys\n");
    while(!IsEmpty_linkStack(s)) {
        Pop_linkStack(s, &topKey);
        printf("poped key: %d\n", topKey);
    }
    
    if(Destroy_linkStack(s))
        printf("stack is destroyed\n");
    return 0;
}