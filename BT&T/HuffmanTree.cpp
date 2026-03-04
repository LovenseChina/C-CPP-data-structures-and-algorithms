#include "HuffmanTree.h"

void _adjust_minHeap_HuffmanTree(HuffmanNode **nodes_pointers, int pos, int length) {
    int i = pos, k;
    HuffmanNode *sift = nodes_pointers[pos];
    while(true) {
        k = i * 2 + 1;
        if(k < length && k + 1 < length && nodes_pointers[k]->weight > nodes_pointers[k + 1]->weight)
            ++k;
        if(k < length && sift->weight > nodes_pointers[k]->weight) {
            nodes_pointers[i] = nodes_pointers[k];
            i = k;
        }
        else {
            nodes_pointers[i] = sift;
            break;
        }
    }
}

void create_HuffmanTree(HuffmanTree &HT) {
    HuffmanNode **nodes_pointers = (HuffmanNode**)malloc(sizeof(HuffmanNode*) * ASCIInum);
    for(int i = 0; i < ASCIInum; ++i) {
        nodes_pointers[i] = (HuffmanNode*)malloc(sizeof(HuffmanNode));
        nodes_pointers[i]->data = i;
        nodes_pointers[i]->weight = ASCII_probability[i];
        nodes_pointers[i]->left = nodes_pointers[i]->right = nullptr;
    }

    //create minHeap
    for(int i = (ASCIInum - 1) / 2; i >= 0; --i)
        _adjust_minHeap_HuffmanTree(nodes_pointers, i, ASCIInum);
    
    //create Huffman Tree
    HuffmanNode *p = nullptr, *lchild = nullptr, *rchild = nullptr;
    for(int i = 0; i < ASCIInum - 1; ++i) {
        lchild = nodes_pointers[0];
        nodes_pointers[0] = nodes_pointers[ASCIInum - 1 - i];
        _adjust_minHeap_HuffmanTree(nodes_pointers, 0, ASCIInum - 1 - i);

        rchild = nodes_pointers[0];

        p = (HuffmanNode*)malloc(sizeof(HuffmanNode));
        p->weight = lchild->weight + rchild->weight;
        p->data = INVALID;
        p->left = lchild;
        p->right = rchild;

        nodes_pointers[0] = p;
        _adjust_minHeap_HuffmanTree(nodes_pointers, 0, ASCIInum - 1 - i);
    }
    HT.root = nodes_pointers[0];
    free(nodes_pointers);
}