#include "graph.h"
#include <stdlib.h>

// cannot be called by user
void _m_BSF(adjMaxtrix &mGraph, int v, int visited[], void (*visit)(int v))
{
    int *queue = (int *)malloc(sizeof(int) * mGraph.vnum);
    int rear = 0, front = 0;
    visited[v] = 1;
    queue[rear++] = v;
    while (rear != front)
    {
        visit(queue[front]);
        int i = queue[front++];
        for (int j = 0; j < mGraph.vnum; ++j)
        {
            if (mGraph.matrix[i][j] > 0 && !visited[j]) {
                visited[j] = 1;
                queue[rear++] = j;
            }
        }
    }
    free(queue);
}

void m_BSF(adjMaxtrix &mGraph, void (*visit)(int v))
{
    if (mGraph.vnum <= 0)
        return;
    int *visited = (int *)malloc(sizeof(int) * mGraph.vnum);
    for (int i = 0; i < mGraph.vnum; ++i)
        visited[i] = 0;
    for (int i = 0; i < mGraph.vnum; ++i)
        if (!visited[i])
            _m_BSF(mGraph, i, visited, visit);
    free(visited);
}

// cannot be called by user
void _l_BSF(adjList &aGraph, int v, int visited[], void (*visit)(int v))
{
    int *queue = (int *)malloc(sizeof(int) * aGraph.vnum);
    int rear = 0, front = 0;
    visited[v] = 1;
    queue[rear++] = v;
    while (rear != front)
    {
        visit(queue[front]);
        int i = queue[front++];
        for (arcNode *p = aGraph.vexlist[i].firstarc; p != nullptr; p = p->nextarc)
            if (!visited[p->adjVex]) {
                visited[p->adjVex] = 1;
                queue[rear++] = p->adjVex;
            }
    }
    free(queue);
}

void l_BSF(adjList &aGraph, void (*visit)(int v))
{
    if (aGraph.vnum <= 0)
        return;
    int *visited = (int *)malloc(sizeof(int) * aGraph.vnum);
    for (int i = 0; i < aGraph.vnum; ++i)
        visited[i] = 0;
    for (int i = 0; i < aGraph.vnum; ++i)
        if (!visited[i])
            _l_BSF(aGraph, i, visited, visit);
    free(visited);
}

// cannot be called by user 
void _m_DSF(adjMaxtrix &mGraph, int v, int visited[], void (*visit)(int v)) {
    visited[v] = 1;
    visit(v);
    for(int j = 0; j < mGraph.vnum; ++j)
        if(mGraph.matrix[v][j] > 0 && !visited[j])
            _m_DSF(mGraph, j, visited, visit);
}

void m_DSF(adjMaxtrix &mGraph, void (*visit)(int v)) {
    if(mGraph.vnum <= 0)
        return;
    int *visited = (int*)malloc(sizeof(int) * mGraph.vnum);
    for(int i = 0; i < mGraph.vnum; ++i)
        visited[i] = 0;
    for(int i = 0; i < mGraph.vnum; ++i)
        if(!visited[i])
            _m_DSF(mGraph, i, visited, visit);
    free(visited);
}

// cannot be called by user
void _l_DSF(adjList &aGraph, int v, int visited[], void (*visit)(int v)) {
    visited[v] = 1;
    visit(v);
    for(arcNode *p = aGraph.vexlist[v].firstarc; p != nullptr; p = p->nextarc)
        if(!visited[p->adjVex])
            _l_DSF(aGraph, p->adjVex, visited, visit);
    
}

void l_DSF(adjList &aGraph, void (*visit)(int v)) {
    if(aGraph.vnum <= 0)
        return;
    int *visited = (int*)malloc(sizeof(int) * aGraph.vnum);
    for(int i = 0; i < aGraph.vnum; ++i)
        visited[i] = 0;
    for(int i = 0; i < aGraph.vnum; ++i)
        if(!visited[i])
            _l_DSF(aGraph, i, visited, visit);
    free(visited);
}