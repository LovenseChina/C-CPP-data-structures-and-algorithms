#include "HuffmanTree.h"
int token_size = 0;
char token[MAX_TOKEN_SIZE];
int ts_size = 0;
Pair token_string[BYTEVAR];
double BYTE_frequency[BYTEVAR];

void compute_frequency(const char *str, int length) {
    memset(BYTE_frequency, 0, sizeof(BYTE_frequency));
    for (int i = 0; i < length; ++i)
        BYTE_frequency[(int)str[i]] += 1.0;
}

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
    HuffmanNode **nodes_pointers = (HuffmanNode**)malloc(sizeof(HuffmanNode*) * BYTEVAR);
    for(int i = 0; i < BYTEVAR; ++i) {
        nodes_pointers[i] = (HuffmanNode*)malloc(sizeof(HuffmanNode));
        nodes_pointers[i]->data = i;
        nodes_pointers[i]->weight = BYTE_frequency[i];
        nodes_pointers[i]->left = nodes_pointers[i]->right = nullptr;
    }

    //create minHeap
    for(int i = (BYTEVAR - 1) / 2; i >= 0; --i)
        _adjust_minHeap_HuffmanTree(nodes_pointers, i, BYTEVAR);
    
    //create Huffman Tree
    HuffmanNode *p = nullptr, *lchild = nullptr, *rchild = nullptr;
    for(int i = 0; i < BYTEVAR - 1; ++i) {
        lchild = nodes_pointers[0];
        nodes_pointers[0] = nodes_pointers[BYTEVAR - 1 - i];
        _adjust_minHeap_HuffmanTree(nodes_pointers, 0, BYTEVAR - 1 - i);

        rchild = nodes_pointers[0];

        p = (HuffmanNode*)malloc(sizeof(HuffmanNode));
        p->weight = lchild->weight + rchild->weight;
        p->data = 0;
        p->left = lchild;
        p->right = rchild;

        nodes_pointers[0] = p;
        _adjust_minHeap_HuffmanTree(nodes_pointers, 0, BYTEVAR - 1 - i);
    }
    HT.root = nodes_pointers[0];
    free(nodes_pointers);
}

void token_HuffmanTree(HuffmanNode *root, char lr) {
    if (!root)
        return;
    if ('l' == lr) 
        token[token_size++] = '0';
    else if ('r' == lr)
        token[token_size++] = '1';
    else
        token_size = 0; // root node, reset token_size to zero
    
    if (root->left == nullptr && root->right == nullptr) {  // leaf node means the token is complete and the data is stored in root->data
        token_string[(int)root->data].token = (char *)malloc(token_size);
        token_string[(int)root->data].token_size = token_size;
        memcpy(token_string[(int)root->data].token, token, token_size);
    } else {
        token_HuffmanTree(root->left, 'l');
        token_HuffmanTree(root->right, 'r');
    }

    --token_size; // backtracking
}