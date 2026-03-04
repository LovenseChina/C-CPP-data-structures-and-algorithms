#ifndef SEARCH_NAME_HASH
#define SEARCH_NAME_HASH
#define MAGIC_SEED 5381
#define MAXLength 50

typedef struct Dentry {
    char name[MAXLength];
    unsigned inode;
}Dentry;

typedef struct Directory {
    Dentry *items;
    unsigned size;
}Directory;

unsigned long djb2_hash(const char *str);

#endif