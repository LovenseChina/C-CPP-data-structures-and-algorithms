#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include<stdlib.h>
#include<string.h>

#define BYTEVAR 128
#define MAX_TOKEN_SIZE 256  // This Macro can use undef && define to change the max token size for user if their token size is too large

typedef struct {
    char *token;
    int token_size;
} Pair;

extern int token_size;
extern char token[MAX_TOKEN_SIZE];
extern int ts_size;
extern Pair token_string[BYTEVAR];
extern double BYTE_frequency[BYTEVAR];

typedef struct HuffmanNode {
    char data;
    int weight;
    struct HuffmanNode *left, *right;
}HuffmanNode;

typedef struct HuffmanTree {
    HuffmanNode *root;
}HuffmanTree;

//input data is treated as byte stream so here we use char to store the data and it is easy to HASH without colision
void compute_frequency(const char *str, int length);
void _adjust_minHeap_HuffmanTree(HuffmanNode **nodes_pointers, int pos, int length);
void create_HuffmanTree(HuffmanTree &HT);
void token_HuffmanTree(HuffmanNode *root, char lr = ' '); // lr = ' ' means root, so it has no left or right direction and wont store '0' or '1'

#endif