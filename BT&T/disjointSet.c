#include <stdio.h>

void init_disjointSet(int S[], int size)
{
    for (int i = 0; i < size; ++i)
        S[i] = -1;
}

int root_disjointSet(int S[], int size, int x)
{
    if (x < 0 || x >= size) //防御性编程
        return -1;
    /*
    while(S[x] >= 0)
        x = S[x];
    */
    int root_x = x;
    while (S[root_x] >= 0)
        root_x = S[root_x];
    int current;
    while (S[x] >= 0)   //路径压缩将x到根路径上的中间点都修改其根为第一层的根，即改造为层高为2的树
    {
        current = x;
        x = S[x]; // x指向其父节点
        S[current] = root_x;
    }
    return root_x;
}

int union_disjointSet(int S[], int size, int x, int y)
{
    if (x < 0 || x >= size || y < 0 || y >= size)
        return -1;
    int root_x = root_disjointSet(S, size, x), root_y = root_disjointSet(S, size, y);
    if (root_x == root_y)
        return -1;
    /*
    S[root_x] += S[root_y];
    S[root_y] = root_x;
    */
    if (S[root_x] < S[root_y])
    { // x根下节点多
        S[root_x] += S[root_y];
        S[root_y] = root_x; // 将小树y加入大树x
    }
    else
    {
        S[root_y] += S[root_x];
        S[root_x] = root_y;
    }

    return 1;
}

void print_disjointSet(int S[], int size, const char *msg)
{
    printf("%s\n[index/key]: ", msg);
    for (int i = 0; i < size; i++)
        printf("%2d ", i);

    printf("\n[parrent]:");
    for (int i = 0; i < size; i++)
        printf("%2d ", S[i]);

    printf("\n[root]:");
    for (int i = 0; i < size; i++)
        printf("%2d ", root_disjointSet(S, size, i));
    printf("\n\n");
}

/*
int main()
{
    const int SIZE = 10;
    int set[SIZE];

    printf("===== Disjoint Testing =====\n");

    // 测试1: 初始化
    init_disjointSet(set, SIZE);
    print_disjointSet(set, SIZE, "initialize:");

    // 测试2: 简单合并
    union_disjointSet(set, SIZE, 1, 2);
    union_disjointSet(set, SIZE, 3, 4);
    print_disjointSet(set, SIZE, "merged 1-2, 3-4:");

    // 测试3: 链式合并
    union_disjointSet(set, SIZE, 2, 3);
    print_disjointSet(set, SIZE, "merged 2-3后 (merge two sets):");

    // 测试4: 路径压缩测试
    printf("find root of key \"4\": %d\n", root_disjointSet(set, SIZE, 4));
    print_disjointSet(set, SIZE, "compressed path (4->root):");

    // 测试5: 大小合并测试
    union_disjointSet(set, SIZE, 0, 1); // 小树(0)合并到大树(1-2-3-4)
    print_disjointSet(set, SIZE, "merged 0-1 (small tree merged in big tree):");

    // 测试6: 无效操作测试
    printf("\ntesting invalid operations:\n");
    printf("invalid merge(out of bound): %d\n", union_disjointSet(set, SIZE, -1, 5));
    printf("invalid merge(same sets): %d\n", union_disjointSet(set, SIZE, 2, 4));
    printf("invalid find(out of bound): %d\n", root_disjointSet(set, SIZE, 10));

    // 测试7: 复杂合并
    union_disjointSet(set, SIZE, 5, 6);
    union_disjointSet(set, SIZE, 6, 7);
    union_disjointSet(set, SIZE, 8, 9);
    union_disjointSet(set, SIZE, 7, 8);
    union_disjointSet(set, SIZE, 4, 5); // 连接两个大集合

    print_disjointSet(set, SIZE, "final state:");

    // 测试8: 最终根查询
    printf("final root finding operations:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("root of key %d: %d\n", i, root_disjointSet(set, SIZE, i));
    }

    return 0;
}
*/