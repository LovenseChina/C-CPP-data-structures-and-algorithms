#include "TreeAndForest.h"

void TreeRootFirst_TreeAndForest(Tree T, void (*visit)(ElemType e)) {
    if(!T)
        return;
    visit(T->data);
    TreeRootFirst_TreeAndForest(T->firstchild, visit);
    TreeRootFirst_TreeAndForest(T->nextsibling, visit);
}

void TreeRootLast_TreeAndForest(Tree T, void (*visit)(ElemType e)) {
    if(!T)
        return;
    TreeRootLast_TreeAndForest(T->firstchild, visit);
    visit(T->data);
    TreeRootLast_TreeAndForest(T->nextsibling, visit);
}

BiTree ConvertTreeToBiTree_TreeAndForest(Tree T) {
    
}

Tree ConvertBiTreeToTree_TreeAndForest(BiTree T) {

}