#include "graph.h"
#include <stdlib.h>

void non_weighted(adjMaxtrix &mGraph, int src, int dist[], int path[])
{
    int *visited = (int *)malloc(sizeof(int) * mGraph.vnum);
    int *queue = (int *)malloc(sizeof(int) * mGraph.vnum);
    int rear = 0, front = 0;
    for (int i = 0; i < mGraph.vnum; ++i)
    {
        visited[i] = 0;
        path[i] = -1;
        dist[i] = -1;
    }
    visited[src] = 1;
    dist[src] = 0;
    queue[rear++] = src;

    while (rear != front)
    {
        for (int j = 0; j < mGraph.vnum; ++j)
            if (mGraph.matrix[queue[front]][j] > 0 && !visited[j])
            {
                visited[j] = 1;
                dist[j] = dist[queue[front]] + 1;
                path[j] = queue[front];
                queue[rear++] = j;
            }
        ++front;
    }
    free(queue);
    free(visited);
}

void dijkstra_brutal(adjList &aGraph, int src, int dist[], int path[])
{
    int *find = (int *)malloc(sizeof(int) * aGraph.vnum);
    int current_vex = src;
    for (int i = 0; i < aGraph.vnum; ++i)
    {
        dist[i] = INT_MAX;
        path[i] = -1;
        find[i] = 0;
    }
    dist[src] = 0;
    find[src] = 1;

    for (int i = 1; i < aGraph.vnum; ++i)
    {
        // update dist[] from current vertex
        if (current_vex >= 0)
        {
            for (arcNode *p = aGraph.vexlist[current_vex].firstarc; p != nullptr; p = p->nextarc)
                if (!find[p->adjVex] && dist[p->adjVex] > dist[current_vex] + p->weight) // !find[p->adjVex] 可加可不加，对简单图而言
                {
                    path[p->adjVex] = current_vex;
                    dist[p->adjVex] = dist[current_vex] + p->weight;
                }
        }
        // choose best dist
        int min_dist = INT_MAX;
        int new_vex = -1;
        // add to set
        for (int j = 0; j < aGraph.vnum; ++j)
            if (!find[j] && dist[j] < min_dist)
            {
                new_vex = j;
                min_dist = dist[j];
            }
        if (new_vex >= 0)
            find[new_vex] = 1;
        current_vex = new_vex;
    }
    free(find);
}

void floyd(adjMaxtrix &mGraph, int **&path, int **&cost)
{
    path = (int **)malloc(sizeof(int *) * mGraph.vnum);
    cost = (int **)malloc(sizeof(int *) * mGraph.vnum);
    for (int i = 0; i < mGraph.vnum; ++i)
        path[i] = (int *)malloc(sizeof(int) * mGraph.vnum);
    for (int i = 0; i < mGraph.vnum; ++i)
        for (int j = 0; j < mGraph.vnum; ++j)
        {
            path[i][j] = -1;
            cost[i][j] = mGraph.matrix[i][j];
        }

    for (int k = 0; k < mGraph.vnum; ++k)
        for (int i = 0; i < mGraph.vnum; ++i)
            for (int j = 0; j < mGraph.vnum; ++j)
                if (cost[i][k] <= INT_MAX / 2 && cost[k][j] <= INT_MAX / 2 && cost[i][j] > cost[i][k] + cost[k][j])
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                    path[i][j] = k;
                }
}

int *floyd_path(int **path, int **cost, int u, int v, int vnum)
{
    if (cost[u][v] == INT_MAX)
        return nullptr;
    int index = 1, *re_path = (int *)malloc(sizeof(int) * vnum), &r_index = index;
    for (int i = 0; i < vnum; ++i)
        re_path[i] = -1;
    _floyd_path(path, u, v, re_path, index);
    re_path[0] = u;
    re_path[index] = v;
    return re_path;
}

void _floyd_path(int **path, int u, int v, int *re_path, int &index)
{
    if (path[u][v] == -1)
        return;
    int k = path[u][v];
    _floyd_path(path, u, k, re_path, index);
    re_path[index++] = k;
    _floyd_path(path, k, v, re_path, index);
}