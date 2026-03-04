#ifndef TREE_AND_FOREST_H
#define TREE_AND_FOREST_H

typedef int ElemType;

typedef struct BiNode
{
    struct BiNode *lchild, *rchild;
    ElemType data;
} BiNode, *BiTree;

typedef struct TreeNode
{
    ElemType data;
    struct TreeNode *firstchild, *nextsibling;

} TreeNode, *Tree;

typedef struct Forest
{
    TreeNode *roots;
    int trees_num;
} Forest;

void TreeRootFirst_TreeAndForest(Tree T, void (*visit)(ElemType e));
void TreeRootLast_TreeAndForest(Tree T, void (*visit)(ElemType e));
BiTree ConvertTreeToBiTree_TreeAndForest(Tree T);
Tree ConvertBiTreeToTree_TreeAndForest(BiTree T);

#endif