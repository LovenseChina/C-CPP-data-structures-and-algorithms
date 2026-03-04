#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include<stdlib.h>
#define ASCIInum 128
#define INVALID 128

typedef struct HuffmanNode {
    char data;
    int weight;
    struct HuffmanNode *left, *right;
}HuffmanNode;

typedef struct HuffmanTree {
    HuffmanNode *root;
}HuffmanTree;

//only support ASCII
double ASCII_probability[ASCIInum];
//void compute_probability()
void _adjust_minHeap_HuffmanTree(HuffmanNode **nodes_pointers, int pos, int length);
void create_HuffmanTree(HuffmanTree &HT);
//void path_HuffmanTree(HuffmanNode *root);

#endif