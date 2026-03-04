#include "sort.h"

void bubble_Sort(int A[], int length)
{
    for (int i = 1; i < length; ++i)
    {
        int flag = 0;
        for (int j = 0; j < length - i; ++j)
        { // 升序下每趟排序待排序序列中的最大的值会在最终位置上，故j < length - i
            if (A[j] > A[j + 1])
            {
                int swap_val = A[j];
                A[j] = A[j + 1];
                A[j + 1] = swap_val;
                flag = 1;
            }
        }
        if (!flag) // 未发生交换则已经排序完毕
            return;
    }
}

// cannot be called by user
int _partition(int A[], int lo, int hi)
{
    int pivot = A[lo];
    while (lo < hi)
    {
        while (lo < hi && A[hi] >= pivot)
            --hi; // 相等也移动，否则死循环，所以算法不稳定
        A[lo] = A[hi];
        while (lo < hi && A[lo] <= pivot)
            ++lo;
        A[hi] = A[lo];
    }
    A[lo] = pivot;
    return lo;
}

void quick_Sort(int A[], int length)
{
    if (length <= 1) // 终止条件
        return;
    int pivot = _partition(A, 0, length - 1);
    quick_Sort(A, pivot);
    quick_Sort(A + pivot + 1, length - pivot - 1);
}