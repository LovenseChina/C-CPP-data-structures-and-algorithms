#include "sort.h"
#include <stdlib.h>

void _merge(int A[], int B[], int length_A, int length_B)
{
    int *C = (int *)malloc(sizeof(int) * length_A);
    if (!C)
        return;
    for (int k = 0; k < length_A; ++k)
        C[k] = A[k];
    int i = 0, j = 0, k = 0;
    while (i < length_A && j < length_B)
    {
        if (C[i] < B[j])
        {
            A[k++] = C[i++];
        }
        else
            A[k++] = B[j++];
    }
    while (i < length_A)
        A[k++] = C[i++];
    while (j < length_B)
        A[k++] = B[j++];
    free(C);
}

//{0, 1, 2, 3} l = 4 ml = 2
//{0, 1, 2, 3, 4} l = 5, ml = 2

void merge_Sort(int A[], int length)
{
    int mid_len = length / 2;
    if (mid_len > 0)
    {
        merge_Sort(A, mid_len);
        merge_Sort(A + mid_len, length - mid_len);
        _merge(A, A + mid_len, mid_len, length - mid_len);
    }
}