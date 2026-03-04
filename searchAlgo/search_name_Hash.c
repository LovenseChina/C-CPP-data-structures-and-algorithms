#include "search_name_Hash.h"

unsigned long djb2_hash(const char *str) {
    unsigned long hash = MAGIC_SEED;
    int c;
    while((c = *(str++)))
        hash = ((hash << 5) + hash) + c;
    return hash;
}