#include "sort.h"
#include <limits.h>

void simple_Select(int A[], int length)
{
    for (int i = 0; i < length - 1; ++i)
    {
        int min_index = -1;
        int min_val = INT_MAX;
        for (int j = length - 1; j >= i; --j)
        {
            if (A[j] < min_val)
            {
                min_val = A[j];
                min_index = j;
            }
        }
        A[min_index] = A[i];
        A[i] = min_val;
    }
}
/*
           0
         /   \
        1      2
       /  \   /  \
      3    4  5   6

 (1 - 1) / 2 = 0  (2 - 1) / 2 = 0
 (3 - 1) / 2 = 1  (4 - 1) / 2 = 1
 (5 - 1) / 2 = 2  (6 - 1) / 2 = 2

 parent = (pos - 1) / 2
 lchild = 2 * i + 1, rchild = lchild + 1
*/

// cannot be called by user
void _adjust_MaxHeap(int A[], int pos, int length)
{
    int adj_val = A[pos];
    int i = pos, k;
    while (i < length)
    {
        int adjusted = 0;
        k = i * 2 + 1;
        if (k + 1 < length && A[k] < A[k + 1])
            ++k;
        if (k < length && adj_val < A[k])
        {
            A[i] = A[k];
            i = k;
            adjusted = 1;
        }
        if (!adjusted)
        {
            A[i] = adj_val;
            break;
        }
    }
}

// cannot be called by user
void _create_MaxHeap(int A[], int length)
{
    for (int i = 0; i <= (length - 2) / 2; ++i)
        _adjust_MaxHeap(A, (length - 2) / 2 - i, length);
}

void heap_Sort(int A[], int length)
{
    _create_MaxHeap(A, length);
    for (int i = length - 1; i > 0; --i)
    {
        int swap_val = A[i];
        A[i] = A[0];
        A[0] = swap_val;
        _adjust_MaxHeap(A, 0, i);
    }
}