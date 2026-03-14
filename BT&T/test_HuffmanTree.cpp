#include "HuffmanTree.h"
#include "HuffmanTree.cpp"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// 验证所有编码是否构成前缀码（无冲突）
bool is_prefix_code() {
    for (int i = 0; i < BYTEVAR; ++i) {
        if (token_string[i].token_size == 0) continue;
        for (int j = i + 1; j < BYTEVAR; ++j) {
            if (token_string[j].token_size == 0) continue;
            int min_len = token_string[i].token_size < token_string[j].token_size ?
                          token_string[i].token_size : token_string[j].token_size;
            if (memcmp(token_string[i].token, token_string[j].token, min_len) == 0) {
                return false; // 互为前缀
            }
        }
    }
    return true;
}

// 计算加权路径长度 (WPL)
double weighted_path_length() {
    double wpl = 0.0;
    for (int i = 0; i < BYTEVAR; ++i) {
        if (token_string[i].token_size > 0) {
            wpl += BYTE_frequency[i] * token_string[i].token_size;
        }
    }
    return wpl;
}

int main() {
    // 测试字符串
    const char *test_str = "this is a test string for huffman tree";
    int len = strlen(test_str);

    // 计算频率
    compute_frequency(test_str, len);

    printf("Input string: %s\n", test_str);
    printf("Length: %d\n", len);

    // 打印非零频率
    printf("\nFrequencies:\n");
    for (int i = 0; i < BYTEVAR; ++i) {
        if (BYTE_frequency[i] > 0) {
            printf("  '%c' (ASCII %d): %.0f\n", i, i, BYTE_frequency[i]);
        }
    }

    // 构建哈夫曼树
    HuffmanTree HT;
    create_HuffmanTree(HT);

    // 生成编码
    token_HuffmanTree(HT.root);

    // 打印编码
    printf("\nHuffman Codes:\n");
    for (int i = 0; i < BYTEVAR; ++i) {
        if (token_string[i].token_size > 0) {
            printf("  '%c': ", i);
            for (int j = 0; j < token_string[i].token_size; ++j)
                putchar(token_string[i].token[j]);
            printf("\n");
        }
    }

    // 验证前缀码
    if (is_prefix_code()) {
        printf("\nPrefix code check: PASSED\n");
    } else {
        printf("\nPrefix code check: FAILED (codes conflict)\n");
    }

    // 输出加权路径长度
    double wpl = weighted_path_length();
    printf("Weighted path length: %f\n", wpl);

    return 0;
}