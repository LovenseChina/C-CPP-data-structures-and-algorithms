#include "graph.h"
#include ".\BT&T\disjointSet.c"
#include <stdlib.h>
#include <limits>

void prim(adjMaxtrix &mGraph, int T[], int v)
{
    int *dist = (int *)malloc(sizeof(int) * mGraph.vnum);
    int *inMST = (int *)malloc(sizeof(int) * mGraph.vnum);
    for (int i = 0; i < mGraph.vnum; ++i)
    {
        T[i] = -1;
        inMST[i] = 0;
        dist[i] = INT_MAX;
    }
    T[0] = v;
    int Tindex = 1;
    inMST[v] = 1;
    dist[v] = 0;

    int current_vex = v;
    for (int i = 1; i < mGraph.vnum; ++i)
    {
        int min_dist = INT_MAX, next_vex = -1;
        for (int j = 0; j < mGraph.vnum; ++j)
        {
            if (!inMST[j] && dist[j] > mGraph.matrix[current_vex][j])
                dist[j] = mGraph.matrix[current_vex][j];
            if (!inMST[j] && dist[j] < min_dist)
            {
                min_dist = dist[j];
                next_vex = j;
            }
        }
        if (next_vex >= 0)
        {
            T[Tindex++] = next_vex;
            inMST[next_vex] = 1;
            current_vex = next_vex;
        }
    }

    free(inMST);
    free(dist);
}

void _adjust_min(MSTarc *heap, int anum, int pos)
{
    MSTarc arc = heap[pos];
    int i = pos, k;
    while (i < anum)
    {
        k = 2 * i + 1;
        if (k + 1 < anum && heap[k].adjArc->weight > heap[k + 1].adjArc->weight)
            ++k;
        if (k < anum && arc.adjArc->weight > heap[k].adjArc->weight)
        {
            heap[i] = heap[k];
            i = k;
        }
        else
            break;
    }
    heap[i] = arc;
}

void _create_minHeap(MSTarc *heap, int anum)
{
    for (int i = (anum - 1) / 2; i >= 0; --i)
        _adjust_min(heap, anum, i);
}

void kruskal(adjList &aGraph, MSTarc T[])
{
    if (aGraph.vnum <= 1)
        return;
    // 初始化顶点并查集
    int *S = (int *)malloc(sizeof(int) * aGraph.vnum);
    init_disjointSet(S, aGraph.vnum);
    // 构造边的小顶堆
    int realEdge_num = aGraph.anum / 2;
    MSTarc *heap = (MSTarc *)malloc(sizeof(MSTarc) * realEdge_num);
    int count = 0;
    for (int i = 0; i < aGraph.vnum; ++i)
        for (arcNode *p = aGraph.vexlist[i].firstarc; p != nullptr; p = p->nextarc)
            if (p->adjVex > i)
            { // 无向图只存储上三角矩阵以提高效率
                heap[count].adjArc = p;
                heap[count++].arcHead = i;
            }
    _create_minHeap(heap, realEdge_num); // Heapfy

    int inMST = 0; // 记录已经加入边数量
    for (int i = 0; i < realEdge_num && inMST < aGraph.vnum - 1; ++i)
    { // 终止条件是找到n - 1条边（n个顶点）或者边的小顶堆筛选完毕
        int root1 = root_disjointSet(S, aGraph.vnum, heap[0].arcHead),
            root2 = root_disjointSet(S, aGraph.vnum, heap[0].adjArc->adjVex);
        if (root1 != root2)
        {                                                                               // 如果不构成环则
            union_disjointSet(S, aGraph.vnum, heap[0].arcHead, heap[0].adjArc->adjVex); // 加入此边，合并两个顶点对应集合
            T[inMST++] = heap[0];                                                       // we don't need deep copy that T[] is read only and reliability is asured by caller
        }
        heap[0] = heap[realEdge_num - 1 - i];
        if (realEdge_num - 1 - i > 0) // 保证对辅助函数的正确传参
            _adjust_min(heap, realEdge_num - 1 - i, 0);
    }
    free(S);
    free(heap);
}