#include "graph.h"
#include<stdlib.h>

int simple_toplogical_Sort(adjList &aGraph, int sequence[]) {
    // 统计顶点入度 
    int *indegree = (int*)calloc(aGraph.vnum, sizeof(int)); // 分配辅助空间并置0
    for(int i = 0; i < aGraph.vnum; ++i)
        for(arcNode *p = aGraph.vexlist[i].firstarc; p != nullptr; p = p->nextarc)
            ++(indegree[p->adjVex]);
    // 开始拓扑排序
    int sequence_index = 0;
    int *insequence = (int*)malloc(sizeof(int) * aGraph.vnum);
    for(int i = 0; i < aGraph.vnum; ++i)
        insequence[i] = 0;
    for(int i = 0; i < aGraph.vnum; ++i) {
        int vex = -1;
        for(int j = 0; j < aGraph.vnum; ++j)    // 找一个入度为0且不在已排序序列的顶点
            if(!insequence[j] && indegree[j] == 0) {
                vex = j;
                break;
            }
        if(vex < 0) // 有环则排序失败
            return 0;
        for(arcNode *p = aGraph.vexlist[vex].firstarc; p != nullptr; p = p->nextarc)
            --(indegree[p->adjVex]);
        sequence[sequence_index++] = vex;
        insequence[vex] = 1;
    }
    free(indegree);
    free(insequence);
    return 1;
}

int kahn_toplogical_Sort(adjList &aGraph, int sequence[]) {
    // 计算顶点入度 
    int *indegree = (int*)calloc(aGraph.vnum, sizeof(int));
    for(int i = 0; i < aGraph.vnum; ++i)
        for(arcNode *p = aGraph.vexlist[i].firstarc; p != nullptr; p = p->nextarc) {
            ++(indegree[p->adjVex]);
        }
    // 顶点队列初始化
    int *vex_Q = (int*)malloc(sizeof(int) * aGraph.vnum);
    int rear = 0, front = 0;
    for(int i = 0; i < aGraph.vnum; ++i)
        if(indegree[i] == 0)
            vex_Q[rear++] = i;
    int insequence = 0;
    while(rear != front) {
        int vex = vex_Q[front++];
        for(arcNode *p = aGraph.vexlist[vex].firstarc; p != nullptr; p = p->nextarc) {
            --(indegree[p->adjVex]);
            if(indegree[p->adjVex] == 0)
                vex_Q[rear++] = p->adjVex;
        }
        sequence[insequence++] = vex;
    }
    free(indegree);
    free(vex_Q);
    if(insequence < aGraph.vnum)
        return 0;
    return 1;
}