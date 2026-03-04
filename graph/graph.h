#ifndef GRAPH_H
#define GRAPH_H
#define MAXSIZE 50 // vertexs only support numbering from 0 to 49

// vertex numbering should be continious and start from zero to simplify find adjacent vertex
// not support negative weight
typedef struct adjMaxtrix
{
    int matrix[MAXSIZE][MAXSIZE];
    int vnum;
} adjMaxtrix;

typedef struct arcNode
{
    int adjVex;
    int weight;
    struct arcNode *nextarc;
} arcNode;

typedef struct vexNode
{
    int vex;
    struct arcNode *firstarc;
    char *info;
} vexNode;

typedef struct adjList
{
    vexNode vexlist[MAXSIZE];
    int vnum;
    int anum;
} adjList;

typedef struct MSTarc
{
    arcNode *adjArc;
    int arcHead;
} MSTarc;

// file: traverse.cpp
void _m_BSF(adjMaxtrix &mGraph, int v, int visited[], void (*visit)(int v));
void m_BSF(adjMaxtrix &mGraph, void (*visit)(int v));
void _l_BSF(adjList &aGraph, int v, int visited[], void (*visit)(int v));
void l_BSF(adjList &aGraph, void (*visit)(int v));
void _m_DSF(adjMaxtrix &mGraph, int v, int visited[], void (*visit)(int v));
void m_DSF(adjMaxtrix &mGraph, void (*visit)(int v));
void _l_DSF(adjList &aGraph, int v, int visited[], void (*visit)(int v));
void l_DSF(adjList &aGraph, void (*visit)(int v));

// file: mst.cpp
void prim(adjMaxtrix &mGraph, int T[], int v);
void _adjust_min(MSTarc *heap, int anum, int pos);
void _create_minHeap(MSTarc *heap, int anum);
void kruskal(adjList &aGraph, MSTarc T[]);

// file: shortest_path.cpp
void non_weighted(adjMaxtrix &mGraph, int src, int dist[], int path[]);
void dijkstra_brutal(adjList &aGraph, int src, int dist[], int path[]);
void floyd(adjMaxtrix &mGraph, int **&path, int **&cost);
int *floyd_path(int **path, int **cost, int u, int v, int vnum);
void _floyd_path(int **path, int u, int v, int *re_path, int &index);

// file: toplogy.cpp
int simple_toplogical_Sort(adjList &aGraph, int sequence[]);
int kahn_toplogical_Sort(adjList &aGraph, int sequence[]);
// int critical_path(adjList &aGraph, vexNode *&path);

#endif