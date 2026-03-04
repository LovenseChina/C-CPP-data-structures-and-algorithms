#include "sort.h"

void simple_Insertion(int A[], int length)
{
    for (int i = 1; i < length; ++i)
    {
        if (A[i] < A[i - 1])
        {
            int j = i;
            int e = A[i];
            for (; j > 0 && e < A[j - 1]; --j)
                A[j] = A[j - 1];
            A[j] = e;
        }
    }
}

// binary search
void search_optInsertion(int A[], int length)
{
    for (int i = 1; i < length; ++i)
    {
        if (A[i] < A[i - 1])
        {
            int lo = 0, hi = i - 1;
            while (lo < hi)
            {
                int mid = (lo + hi) / 2;
                if (A[i] < A[mid])
                    hi = mid;
                else
                    lo = mid + 1;
            }

            int e = A[i];
            for (int j = i; j > lo; --j)
                A[j] = A[j - 1];
            A[lo] = e;
        }
    }
}

// Shell Sort should be implemented through imitating simple insertion sort
void shell(int A[], int length)
{
    for (int dk = length / 2; dk > 0; dk /= 2)
    {
        for (int i = dk; i < length; ++i)
        {
            if (A[i] < A[i - dk])
            {
                int e = A[i];
                int j = i;
                for (; j - dk >= 0 && e < A[j - dk]; j -= dk)
                    A[j] = A[j - dk];
                A[j] = e;
            }
        }
    }
}