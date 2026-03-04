#ifndef SINGLE_ELEM_SEARCH
#define SINGLE_ELEM_SEARCH
#define  MAXSIZE 50

typedef struct searchTable {
    int searchTable[MAXSIZE];
    int length;
}searchTable;

typedef struct BSTnode {
    struct BSTnode *left, *right;
    int data;
}BSTnode, *BST;

//sequential list search
searchTable* batch_create_SST(int *nums, int length);
int sequential_Search(searchTable , int e);
void _adjust_maxHeap_SST(searchTable SST, int pos, int length);
void sort_SST(searchTable SST);
int sequential_Search_Sorted(searchTable SST, int e);
int binary_Search(searchTable SST, int e);

//simple BST
BST batch_create_BST(int a[], int n);
void destroy_BST(BST &T);
bool insert_BST(BST &T, int e);
bool delete_BST(BST &T, int e);
bool find_BST(BST &T, int e);

#endif