#include<stdio.h>

int BF(char *s, char *p) {
    int slen = 0;
    while(s[slen] != '\0')
        ++slen;
    int plen = 0;
    while(p[plen] != '\0')
        ++plen;
    
    int i = 0, j = 0;
    while(i < slen && j < plen) {
        if(s[i] == p[j]) {
            ++i;
            ++j;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
    }
    if(j == plen)
        return i - j;
    else
        return -1;
}

int main() {
    char s[] = "aabaaabbaaabaab";    //s.Length = 15
    char p[] = "baab";  //p.Length = 4

    printf("%d\n", BF(s, p));

    return 0;
}