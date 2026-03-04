#ifndef SORT_H
#define SORT_H

//file: insertion.c 
void simple_Insertion(int A[], int length);
void search_optInsertion(int A[], int length);
void shell(int A[], int length);

//file: swap.c 
void bubble_Sort(int A[], int length);
int _partition(int A[], int lo, int hi);
void quick_Sort(int A[], int length);

//file: select.c 
void simple_Select(int A[], int length);
void _adjust_MaxHeap(int A[], int pos, int length);
void _create_MaxHeap(int A[], int length);
void heap_Sort(int A[], int length);

//file: merge_Sort.c 
void _merge(int A[], int B[], int lenght_A, int length_B);
void merge_Sort(int A[], int length);

#endif