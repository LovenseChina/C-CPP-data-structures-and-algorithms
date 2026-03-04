#include "singleElemSearch.h"
#include <stdlib.h>

searchTable *batch_create_SST(int *nums, int length)
{
    if (length <= 0 || length >= MAXSIZE - 1)
        return nullptr;
    searchTable *SST = (searchTable *)malloc(sizeof(searchTable));
    SST->length = length;
    for (int i = 1; i <= length; ++i)
        SST->searchTable[i] = nums[i - 1];
    return SST;
}

int sequential_Search(searchTable SST, int e)
{
    SST.searchTable[0] = e;
    int i = SST.length;
    for (; i >= 0; --i)
        if (SST.searchTable[i] == e)
            break;
    return i;
}

void _adjust_maxHeap_SST(searchTable SST, int pos, int length)
{
    int i = pos, sift = SST.searchTable[pos], k;
    while (true)
    {
        k = 2 * i;
        if (k < length && k + 1 < length && SST.searchTable[k] < SST.searchTable[k + 1])
            ++k;
        if (k < length && SST.searchTable[k] > sift)
        {
            SST.searchTable[i] = SST.searchTable[k];
            i = k;
        }
        else
        {
            SST.searchTable[i] = sift;
            break;
        }
    }
}

void sort_SST(searchTable SST)
{
    for (int i = SST.length / 2; i >= 1; --i)
        _adjust_maxHeap_SST(SST, i, SST.length);
    for (int i = SST.length; i >= 2; --i)
    {
        SST.searchTable[0] = SST.searchTable[1];
        SST.searchTable[1] = SST.searchTable[i];
        SST.searchTable[i] = SST.searchTable[0];
        _adjust_maxHeap_SST(SST, 1, i - 1);
    }
}

int sequential_Search_Sorted(searchTable SST, int e)
{
    SST.searchTable[0] = e;
    int i = SST.length;
    for (; i >= 0 && e > SST.searchTable[i]; --i)
        ;
    if (SST.searchTable[i] == e)
        return i;
    else
        return 0;
}

int binary_Search(searchTable SST, int e)
{
    int lo = 1, hi = SST.length, mid = (lo + hi) / 2;
    while (lo < hi)
    {
        if (e > SST.searchTable[mid])
            lo = mid + 1;
        else if (e < SST.searchTable[mid])
            hi = mid - 1;
        else
            break;
        mid = (lo + hi) / 2;
    }
    if (SST.searchTable[mid] == e)
        return mid;
    else
        return 0;
}

BST batch_create_BST(int a[], int n)
{
    BST T = nullptr;
    for (int i = 0; i < n; ++i)
        insert_BST(T, a[i]);
    return T;
}

void destroy_BST(BST &T)
{
    if (!T)
        return;
    destroy_BST(T->left);
    destroy_BST(T->right);
    free(T);
    T = nullptr;
}

bool insert_BST(BST &T, int e)
{
    if (!T)
    {
        T = (BSTnode *)malloc(sizeof(BSTnode));
        T->data = e;
        T->left = T->right = nullptr;
        return true;
    }
    if (e > T->data)
        return insert_BST(T->right, e);
    else if (e < T->data)
        return insert_BST(T->left, e);
    return false;
}

bool delete_BST(BST &T, int e)
{
    if (!T) // 空树删除失败
        return false;
    if (T->data == e) // 特殊处理根节点删除
    {
        if (T->left && T->right) // 根有左右子树
        {
            BSTnode *p = T, *q = T->left;
            while (q->right) // 找到根节点的前驱以及前驱的父结点
            {
                p = q;
                q = q->right;
            }
            T->data = q->data; // 覆盖根的元素
            // 以下删除q
            if (p->left == q)
                p->left = q->left != nullptr ? q->left : q->right; // 这里可以处理叶节点情况
            else
                p->right = q->left != nullptr ? q->left : q->right; // 同上
            free(q);
            q = nullptr;
        }
        else // 仅有左或右子树以及叶结点情况
        {
            BSTnode *del = T;
            T = T->left != nullptr ? T->left : T->right; // 事实上这里也能处理单节点情况
            free(del);
            del = nullptr;
        }
    }
    else // 删除内部结点
    {
        BSTnode *p = nullptr, *q = T;
        while (q && q->data != e) // 查找待删除结点及其父结点
        {
            p = q;
            q = q->data > e ? q->left : q->right;
        }
        if (!q) // 没有这个结点删除失败
            return false;
        if (q->left && q->right) // 具有左右子树的结点删除
        {
            BSTnode *pre = q, *del = q->left;
            while (del->right) // 寻找待删除结点的中序直接前驱以及这个前驱的父结点
            {
                pre = del;
                del = del->right;
            }
            q->data = del->data; // 前驱直接覆盖原本待删除结点
            // 以下删除del
            if (pre->left == del)
                pre->left = del->left != nullptr ? del->left : del->right; // 可以处理叶结点情况
            else
                pre->right = del->left != nullptr ? del->left : del->right;
            ; // 同上
            free(del);
            del = nullptr;
        }
        else    // 仅有单子树的结点或叶结点删除
        {
            if (p->left == q)
                p->left = q->left != nullptr ? q->left : q->right; // 根据这里可以将前面的叶结点删除作优化掉
            else
                p->right = q->left != nullptr ? q->left : q->right; // 同上
            free(q);
            q = nullptr;
        }
    }
    return true;
}

bool find_BST(BST &T, int e)
{
    BSTnode *p = T;
    while (p)
    {
        if (e > p->data)
            p = p->right;
        else if (e < p->data)
            p = p->left;
        else
            break;
        ;
    }
    if (p)
        return true;
    else
        return false;
}