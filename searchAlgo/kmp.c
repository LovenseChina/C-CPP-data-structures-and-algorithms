#include<stdio.h>

//next[j]计算方式为
//next[j] = 
//1) -1, if j == 0
//2) max{k | 'p1 p2 ... pk-1' == 'pj-k+1 pj-k+2 ... pj-1'}, if j > 1且'p1 p2 ... pk-1' != NULL
//3) 0, 其他
void get_next(char *pattern, int *next, int length) {
    int i = 0, j = -1;
    next[0] = -1; //动态规划初始条件
    while(i < length - 1) {
        if(-1 == j || pattern[i] == pattern[j]) {   //j = -1时直接自增，此时 j = 0, i = 1,此时若p[1]失配，则之前匹配成功的仅有1个元素，显然为其他情况，于转移公式一致
            ++i;                                    //注意到i指向为模式串后部,j为前部,目标是检查当p[i]失配后,应该转移到何处
            ++j;                                    //这里有个大前提,就是在p中的前后部分别存在两个连续的j个字符构成的相等串
            next[i] = j;                            //事实上,这就是情况2
        }                                           //因此如果说这里追加一个字符也相等,那么显然,此时就是这个j值
        else
            j = next[j];                            //当不相等时,则可以看作此时失配,那么依据next数组的含义,就可以回溯模式串前部指针作新的匹配
    }   //这里的动态规划方式是从前往后的,并且注意到对于next[j]我们只关心前面0...j-1的字符情况所以说这里会对i和j自增
}

//get_nextval的方法是在get_next的基础上,每一次确定next[i]时,必须要考察p[i]与p[next[i]]的是否一致,当不一致时next[i]就选取此值,否则往前回溯一次,这里注意只回溯一次因为前面是最优子结构,这里比较显然不展开叙述论证
//本质上nextval构造不仅考虑了之前的串匹配情况还综合了当前所指向的这个字符的情况,于是有如下实现
void get_nextval(char *pattern, int *nextval, int length) {
    int i = 0, j = -1;
    nextval[0] = -1;
    while(i < length - 1) {
        if(j == -1 || pattern[i] == pattern[j]) {
            ++i;
            ++j;
            if(pattern[i] != pattern[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        }
        else
            j = nextval[j];
    }
}

int kmp(char *S, char *pattern, int *next, int Slength, int Plength) {
    int i = 0, j = 0;
    while(i < Slength && j < Plength) { //显然的循环成立判断条件
        if(j == -1 || S[i] == pattern[j]) { //按照next数组求法，但是这里不需要修改next数组了
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if(j == Plength)    //返回下标索引
        return i - Plength;
    else
        return - 1;
}

int main() {
    char s[] = "aabaaabbaaabaab";    //s.Length = 15
    char p[] = "baab";  //p.Length = 4

    int next[4];
    get_next(p, next, 4);
    printf("%d\n", kmp(s, p, next, 15, 4));
    
    int nextval[4];
    get_nextval(p, nextval, 4);
    printf("%d\n", kmp(s, p, next, 15, 4));

    return 0;
}