#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include "insertion.c"
#include "swap.c"
#include "select.c"
#include "merge_Sort.c"

// 验证数组是否有序
int is_sorted(int A[], int length) {
    for (int i = 0; i < length - 1; i++) {
        if (A[i] > A[i + 1]) {
            printf("Sort failure at index %d: %d > %d\n", i, A[i], A[i + 1]);
            return 0;
        }
    }
    return 1;
}

// 打印数组内容
void print_array(int A[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// 测试排序算法的函数
void test_sort(void (*sort_func)(int[], int), const char* algo_name, int A[], int length, const char* test_name) {
    // 复制原始数组用于排序
    int* arr_copy = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        arr_copy[i] = A[i];
    }
    
    // 打印测试信息
    printf("\nTesting %s with %s: ", algo_name, test_name);
    if (length < 20) {
        print_array(arr_copy, length);
    } else {
        printf("[large array: %d elements]\n", length);
    }
    
    // 执行排序并计时
    clock_t start = clock();
    sort_func(arr_copy, length);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    
    // 验证结果
    if (is_sorted(arr_copy, length)) {
        printf("PASSED");
        if (length < 20) {
            printf(" -> ");
            print_array(arr_copy, length);
        } else {
            printf(" (Sorted %d elements in %.6f seconds)\n", length, time_spent);
        }
    } else {
        printf("FAILED\n");
    }
    
    free(arr_copy);
}

// 主测试函数
int main() {
    // 定义各种测试用例
    int empty[] = {};
    int single[] = {42};
    int two_ordered[] = {3, 7};
    int two_reversed[] = {7, 3};
    int random[] = {5, 2, 9, 1, 5, 6};
    int sorted[] = {1, 2, 3, 4, 5};
    int reversed[] = {9, 7, 5, 3, 1};
    int duplicates[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int negatives[] = {0, -5, 3, -2, 1};
    int extremes[] = {INT_MIN, INT_MAX, 0};
    int all_same[] = {7, 7, 7, 7, 7};
    int partial_sorted[] = {1, 3, 2, 4, 5};
    int zigzag[] = {9, 1, 8, 2, 7, 3};
    int min_max_middle[] = {8, 8, 2, 5, 3, 3};
    int single_diff[] = {8, 8, 8, 1, 8, 8};
    int max_first[] = {9, 1, 2, 3, 0};
    
    // 创建大数组用于性能测试
    const int LARGE_SIZE = 10000;
    int* large_random = (int*)malloc(LARGE_SIZE * sizeof(int));
    int* large_sorted = (int*)malloc(LARGE_SIZE * sizeof(int));
    int* large_reversed = (int*)malloc(LARGE_SIZE * sizeof(int));
    
    srand(time(NULL));
    for (int i = 0; i < LARGE_SIZE; i++) {
        large_random[i] = rand() % 10000;
        large_sorted[i] = i;
        large_reversed[i] = LARGE_SIZE - i;
    }
/*   
    // 测试快速排序
    printf("==================== QUICK SORT TESTS ====================\n");
    test_sort(quick_Sort, "Quick Sort", empty, 0, "Empty array");
    test_sort(quick_Sort, "Quick Sort", single, 1, "Single element");
    test_sort(quick_Sort, "Quick Sort", two_ordered, 2, "Two elements (ordered)");
    test_sort(quick_Sort, "Quick Sort", two_reversed, 2, "Two elements (reversed)");
    test_sort(quick_Sort, "Quick Sort", random, 6, "Random array");
    test_sort(quick_Sort, "Quick Sort", sorted, 5, "Sorted array");
    test_sort(quick_Sort, "Quick Sort", reversed, 5, "Reversed array");
    test_sort(quick_Sort, "Quick Sort", duplicates, 10, "Duplicate elements");
    test_sort(quick_Sort, "Quick Sort", negatives, 5, "Negative values");
    test_sort(quick_Sort, "Quick Sort", extremes, 3, "Extreme values (INT_MIN/MAX)");
    test_sort(quick_Sort, "Quick Sort", all_same, 5, "All same elements");
    test_sort(quick_Sort, "Quick Sort", partial_sorted, 5, "Partially sorted");
    test_sort(quick_Sort, "Quick Sort", zigzag, 6, "Zigzag pattern");
    test_sort(quick_Sort, "Quick Sort", min_max_middle, 6, "Min/Max in middle");
    test_sort(quick_Sort, "Quick Sort", single_diff, 6, "Single different element");
    test_sort(quick_Sort, "Quick Sort", max_first, 5, "Max at beginning");
    test_sort(quick_Sort, "Quick Sort", large_random, LARGE_SIZE, "Large random array");
    test_sort(quick_Sort, "Quick Sort", large_sorted, LARGE_SIZE, "Large sorted array");
    test_sort(quick_Sort, "Quick Sort", large_reversed, LARGE_SIZE, "Large reversed array");
    
    // 测试希尔排序
    printf("\n==================== SHELL SORT TESTS ====================\n");
    test_sort(shell, "Shell Sort", empty, 0, "Empty array");
    test_sort(shell, "Shell Sort", single, 1, "Single element");
    test_sort(shell, "Shell Sort", two_ordered, 2, "Two elements (ordered)");
    test_sort(shell, "Shell Sort", two_reversed, 2, "Two elements (reversed)");
    test_sort(shell, "Shell Sort", random, 6, "Random array");
    test_sort(shell, "Shell Sort", sorted, 5, "Sorted array");
    test_sort(shell, "Shell Sort", reversed, 5, "Reversed array");
    test_sort(shell, "Shell Sort", duplicates, 10, "Duplicate elements");
    test_sort(shell, "Shell Sort", negatives, 5, "Negative values");
    test_sort(shell, "Shell Sort", extremes, 3, "Extreme values (INT_MIN/MAX)");
    test_sort(shell, "Shell Sort", all_same, 5, "All same elements");
    test_sort(shell, "Shell Sort", partial_sorted, 5, "Partially sorted");
    test_sort(shell, "Shell Sort", zigzag, 6, "Zigzag pattern");
    test_sort(shell, "Shell Sort", min_max_middle, 6, "Min/Max in middle");
    test_sort(shell, "Shell Sort", single_diff, 6, "Single different element");
    test_sort(shell, "Shell Sort", max_first, 5, "Max at beginning");
    test_sort(shell, "Shell Sort", large_random, LARGE_SIZE, "Large random array");
    test_sort(shell, "Shell Sort", large_sorted, LARGE_SIZE, "Large sorted array");
    test_sort(shell, "Shell Sort", large_reversed, LARGE_SIZE, "Large reversed array");

    // 测试堆排序
    printf("\n==================== HEAP SORT TESTS =====================\n");
    test_sort(heap_Sort, "Shell Sort", empty, 0, "Empty array");
    test_sort(heap_Sort, "Shell Sort", single, 1, "Single element");
    test_sort(heap_Sort, "Shell Sort", two_ordered, 2, "Two elements (ordered)");
    test_sort(heap_Sort, "Shell Sort", two_reversed, 2, "Two elements (reversed)");
    test_sort(heap_Sort, "Shell Sort", random, 6, "Random array");
    test_sort(heap_Sort, "Shell Sort", sorted, 5, "Sorted array");
    test_sort(heap_Sort, "Shell Sort", reversed, 5, "Reversed array");
    test_sort(heap_Sort, "Shell Sort", duplicates, 10, "Duplicate elements");
    test_sort(heap_Sort, "Shell Sort", negatives, 5, "Negative values");
    test_sort(heap_Sort, "Shell Sort", extremes, 3, "Extreme values (INT_MIN/MAX)");
    test_sort(heap_Sort, "Shell Sort", all_same, 5, "All same elements");
    test_sort(heap_Sort, "Shell Sort", partial_sorted, 5, "Partially sorted");
    test_sort(heap_Sort, "Shell Sort", zigzag, 6, "Zigzag pattern");
    test_sort(heap_Sort, "Shell Sort", min_max_middle, 6, "Min/Max in middle");
    test_sort(heap_Sort, "Shell Sort", single_diff, 6, "Single different element");
    test_sort(heap_Sort, "Shell Sort", max_first, 5, "Max at beginning");
    test_sort(heap_Sort, "Shell Sort", large_random, LARGE_SIZE, "Large random array");
    test_sort(heap_Sort, "Shell Sort", large_sorted, LARGE_SIZE, "Large sorted array");
    test_sort(heap_Sort, "Shell Sort", large_reversed, LARGE_SIZE, "Large reversed array"); */

    // 测试二路归并排序
    printf("\n==================== MERGE SORT TESTS ====================\n");
    test_sort(heap_Sort, "Shell Sort", empty, 0, "Empty array");
    test_sort(heap_Sort, "Shell Sort", single, 1, "Single element");
    test_sort(heap_Sort, "Shell Sort", two_ordered, 2, "Two elements (ordered)");
    test_sort(heap_Sort, "Shell Sort", two_reversed, 2, "Two elements (reversed)");
    test_sort(heap_Sort, "Shell Sort", random, 6, "Random array");
    test_sort(heap_Sort, "Shell Sort", sorted, 5, "Sorted array");
    test_sort(heap_Sort, "Shell Sort", reversed, 5, "Reversed array");
    test_sort(heap_Sort, "Shell Sort", duplicates, 10, "Duplicate elements");
    test_sort(heap_Sort, "Shell Sort", negatives, 5, "Negative values");
    test_sort(heap_Sort, "Shell Sort", extremes, 3, "Extreme values (INT_MIN/MAX)");
    test_sort(heap_Sort, "Shell Sort", all_same, 5, "All same elements");
    test_sort(heap_Sort, "Shell Sort", partial_sorted, 5, "Partially sorted");
    test_sort(heap_Sort, "Shell Sort", zigzag, 6, "Zigzag pattern");
    test_sort(heap_Sort, "Shell Sort", min_max_middle, 6, "Min/Max in middle");
    test_sort(heap_Sort, "Shell Sort", single_diff, 6, "Single different element");
    test_sort(heap_Sort, "Shell Sort", max_first, 5, "Max at beginning");
    test_sort(heap_Sort, "Shell Sort", large_random, LARGE_SIZE, "Large random array");
    test_sort(heap_Sort, "Shell Sort", large_sorted, LARGE_SIZE, "Large sorted array");
    test_sort(heap_Sort, "Shell Sort", large_reversed, LARGE_SIZE, "Large reversed array");

    // 清理资源
    free(large_random);
    free(large_sorted);
    free(large_reversed);
    
    printf("\nAll tests completed.\n");
    return 0;
}