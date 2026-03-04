#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>
#include"Recursive_Algo.h"
#include"Recursive_Algo.c"

/*
// Helper function: In-order traversal to print BST
void inorder_traversal(BSTNode *root) {
    if(root == NULL) return;
    inorder_traversal(root->lchild);
    printf("%d ", root->key);
    inorder_traversal(root->rchild);
}

// Helper function: Pre-order traversal to print BST
void preorder_traversal(BSTNode *root) {
    if(root == NULL) return;
    printf("%d ", root->key);
    preorder_traversal(root->lchild);
    preorder_traversal(root->rchild);
}

// Helper function: Free all nodes in BST
void free_BST(BSTNode *root) {
    if(root == NULL) return;
    free_BST(root->lchild);
    free_BST(root->rchild);
    free(root);
}

// Helper function: Get height of BST
int get_height(BSTNode *root) {
    if(root == NULL) return 0;
    int left_height = get_height(root->lchild);
    int right_height = get_height(root->rchild);
    return 1 + (left_height > right_height ? left_height : right_height);
}

int main() {
    BSTNode *root = NULL;
    int test_values[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 85};
    int n = sizeof(test_values)/sizeof(test_values[0]);
    
    printf("=== BST Binary Search Tree Test Program ===\n\n");
    
    // Test 1: Insert operation
    printf("Test 1: Insert %d values into BST\n", n);
    for(int i = 0; i < n; i++) {
        root = insert_BSTNode(root, test_values[i]);
        printf("Inserted %d\n", test_values[i]);
    }
    
    printf("\nIn-order traversal result: ");
    inorder_traversal(root);
    printf("\nPre-order traversal result: ");
    preorder_traversal(root);
    printf("\nTree height: %d\n", get_height(root));
    
    // Test 2: Search operation
    printf("\n\nTest 2: Search operation\n");
    int search_values[] = {50, 20, 65, 90, 15, 85};
    for(int i = 0; i < 6; i++) {
        int found = search_BST(root, search_values[i]);
        printf("Search %d: %s\n", search_values[i], found ? "Found" : "Not found");
    }
    
    // Test 3: Delete leaf node (no children)
    printf("\n\nTest 3: Delete leaf node 10\n");
    root = erase_BSTNode(root, 10);
    printf("In-order traversal after deletion: ");
    inorder_traversal(root);
    printf("\nPre-order traversal after deletion: ");
    preorder_traversal(root);
    
    // Test 4: Delete node with one child
    printf("\n\n\nTest 4: Delete node with one child 20 (now should have only left child 25)\n");
    root = erase_BSTNode(root, 20);
    printf("In-order traversal after deletion: ");
    inorder_traversal(root);
    
    // Test 5: Delete node with two children (root node)
    printf("\n\n\nTest 5: Delete node with two children (root) 50\n");
    root = erase_BSTNode(root, 50);
    printf("In-order traversal after deletion: ");
    inorder_traversal(root);
    printf("\nPre-order traversal after deletion: ");
    preorder_traversal(root);
    
    // Test 6: Delete non-existent node
    printf("\n\n\nTest 6: Attempt to delete non-existent node 99\n");
    root = erase_BSTNode(root, 99);
    printf("In-order traversal after deletion attempt: ");
    inorder_traversal(root);
    
    // Test 7: Boundary test - Insert duplicate value
    printf("\n\n\nTest 7: Insert duplicate value 30\n");
    root = insert_BSTNode(root, 30);
    printf("In-order traversal after insertion: ");
    inorder_traversal(root);
    printf("\n(Note: BST should not have duplicate values, so 30 should not be inserted again)");
    
    // Test 8: Search verification after deletions
    printf("\n\n\nTest 8: Search verification after deletions\n");
    int verify_values[] = {50, 30, 60, 10, 40};
    for(int i = 0; i < 5; i++) {
        int found = search_BST(root, verify_values[i]);
        printf("Search %d: %s\n", verify_values[i], found ? "Found" : "Not found");
    }
    
    // Test 9: Continuous insert and delete operations
    printf("\n\nTest 9: Continuous operations test\n");
    printf("Insert 5, 95\n");
    root = insert_BSTNode(root, 5);
    root = insert_BSTNode(root, 95);
    printf("In-order traversal: ");
    inorder_traversal(root);
    
    printf("\n\nDelete 30, 70\n");
    root = erase_BSTNode(root, 30);
    root = erase_BSTNode(root, 70);
    printf("In-order traversal: ");
    inorder_traversal(root);
    
    // Final status
    printf("\n\n=== Final Status ===\n");
    printf("In-order traversal result: ");
    inorder_traversal(root);
    printf("\nPre-order traversal result: ");
    preorder_traversal(root);
    printf("\nTree height: %d\n", get_height(root));
    
    // Free memory
    free_BST(root);
    
    printf("\n=== Test completed, memory freed ===\n");
    
    return 0;
}
*/

// 辅助函数声明
void inorder_traversal(AVLNode *root);
void preorder_traversal(AVLNode *root);
int get_tree_height(AVLNode *root);
int is_avl_valid(AVLNode *root);
int is_bst_valid(AVLNode *root, int min, int max);
void free_avl_tree(AVLNode *root);
int get_node_count(AVLNode *root);
void print_avl_structure(AVLNode *root, int level);

// 测试函数声明
void test_basic_insertion();
void test_deletion_cases();
void test_avl_property();
void test_random_operations();
void test_edge_cases();
void test_large_dataset();

int main() {
    srand(time(NULL));
    
    printf("==========================\n");
    printf("   AVL TREE TEST SUITE\n");
    printf("==========================\n\n");
    
    // 测试1：基础插入测试
    printf("TEST 1: Basic Insertion Test\n");
    printf("==============================\n");
    test_basic_insertion();
    printf("\n");
    
    // 测试2：删除测试
    printf("TEST 2: Deletion Test Cases\n");
    printf("==============================\n");
    test_deletion_cases();
    printf("\n");
    
    // 测试3：AVL性质验证
    printf("TEST 3: AVL Property Validation\n");
    printf("==============================\n");
    test_avl_property();
    printf("\n");
    
    // 测试4：随机操作测试
    printf("TEST 4: Random Operations Test\n");
    printf("==============================\n");
    test_random_operations();
    printf("\n");
    
    // 测试5：边界情况测试
    printf("TEST 5: Edge Cases Test\n");
    printf("==============================\n");
    test_edge_cases();
    printf("\n");
    
    // 测试6：大数据集测试
    printf("TEST 6: Large Dataset Test\n");
    printf("==============================\n");
    test_large_dataset();
    printf("\n");
    
    printf("==========================\n");
    printf("   ALL TESTS COMPLETED\n");
    printf("==========================\n");
    
    return 0;
}

// ==================== 辅助函数实现 ====================

void inorder_traversal(AVLNode *root) {
    if (!root) return;
    inorder_traversal(root->lchild);
    printf("%d(h=%d) ", root->key, root->height);
    inorder_traversal(root->rchild);
}

void preorder_traversal(AVLNode *root) {
    if (!root) return;
    printf("%d(h=%d) ", root->key, root->height);
    preorder_traversal(root->lchild);
    preorder_traversal(root->rchild);
}

int get_tree_height(AVLNode *root) {
    if (!root) return 0;
    int left_height = get_tree_height(root->lchild);
    int right_height = get_tree_height(root->rchild);
    return 1 + (left_height > right_height ? left_height : right_height);
}

int is_avl_valid(AVLNode *root) {
    if (!root) return 1;
    
    // 检查当前节点是否平衡
    int left_height = root->lchild ? root->lchild->height : 0;
    int right_height = root->rchild ? root->rchild->height : 0;
    int balance = left_height - right_height;
    
    if (balance < -1 || balance > 1) {
        printf("Node %d is unbalanced: balance = %d (left_height=%d, right_height=%d)\n", 
               root->key, balance, left_height, right_height);
        return 0;
    }
    
    // 检查高度是否正确
    int expected_height = 1;
    if (root->lchild && root->rchild) {
        expected_height = (root->lchild->height > root->rchild->height ? 
                          root->lchild->height : root->rchild->height) + 1;
    } else if (root->lchild) {
        expected_height = root->lchild->height + 1;
    } else if (root->rchild) {
        expected_height = root->rchild->height + 1;
    }
    
    if (root->height != expected_height) {
        printf("Node %d height incorrect: actual=%d, expected=%d\n", 
               root->key, root->height, expected_height);
        return 0;
    }
    
    // 递归检查子树
    return is_avl_valid(root->lchild) && is_avl_valid(root->rchild);
}

int is_bst_valid(AVLNode *root, int min, int max) {
    if (!root) return 1;
    
    if (root->key < min || root->key > max) {
        printf("BST property violated at node %d (expected range: %d to %d)\n", 
               root->key, min, max);
        return 0;
    }
    
    return is_bst_valid(root->lchild, min, root->key - 1) &&
           is_bst_valid(root->rchild, root->key + 1, max);
}

void free_avl_tree(AVLNode *root) {
    if (!root) return;
    free_avl_tree(root->lchild);
    free_avl_tree(root->rchild);
    free(root);
}

int get_node_count(AVLNode *root) {
    if (!root) return 0;
    return 1 + get_node_count(root->lchild) + get_node_count(root->rchild);
}

void print_avl_structure(AVLNode *root, int level) {
    if (!root) {
        printf("%*sNULL\n", level * 4, "");
        return;
    }
    
    printf("%*s%d (h=%d)\n", level * 4, "", root->key, root->height);
    print_avl_structure(root->lchild, level + 1);
    print_avl_structure(root->rchild, level + 1);
}

// ==================== 测试函数实现 ====================

void test_basic_insertion() {
    printf("Test Case 1.1: Insert ascending sequence (1 to 10)\n");
    AVLNode *root1 = NULL;
    for (int i = 1; i <= 10; i++) {
        root1 = insert_AVLNode(root1, i);
        if (!is_avl_valid(root1)) {
            printf("  ERROR: Tree invalid after inserting %d\n", i);
            break;
        }
    }
    printf("  Nodes: %d, Height: %d, Balanced: %s\n", 
           get_node_count(root1), root1 ? root1->height : 0,
           is_avl_valid(root1) ? "YES" : "NO");
    printf("  In-order: ");
    inorder_traversal(root1);
    printf("\n");
    free_avl_tree(root1);
    
    printf("\nTest Case 1.2: Insert descending sequence (10 to 1)\n");
    AVLNode *root2 = NULL;
    for (int i = 10; i >= 1; i--) {
        root2 = insert_AVLNode(root2, i);
        if (!is_avl_valid(root2)) {
            printf("  ERROR: Tree invalid after inserting %d\n", i);
            break;
        }
    }
    printf("  Nodes: %d, Height: %d, Balanced: %s\n", 
           get_node_count(root2), root2 ? root2->height : 0,
           is_avl_valid(root2) ? "YES" : "NO");
    printf("  In-order: ");
    inorder_traversal(root2);
    printf("\n");
    free_avl_tree(root2);
    
    printf("\nTest Case 1.3: Insert specific pattern (30, 20, 40, 10, 25, 35, 50)\n");
    int pattern1[] = {30, 20, 40, 10, 25, 35, 50};
    int n1 = sizeof(pattern1)/sizeof(pattern1[0]);
    AVLNode *root3 = NULL;
    for (int i = 0; i < n1; i++) {
        root3 = insert_AVLNode(root3, pattern1[i]);
        if (!is_avl_valid(root3)) {
            printf("  ERROR: Tree invalid after inserting %d\n", pattern1[i]);
            break;
        }
    }
    printf("  Nodes: %d, Height: %d, Balanced: %s\n", 
           get_node_count(root3), root3 ? root3->height : 0,
           is_avl_valid(root3) ? "YES" : "NO");
    printf("  In-order: ");
    inorder_traversal(root3);
    printf("\n");
    free_avl_tree(root3);
}

void test_deletion_cases() {
    printf("Test Case 2.1: Delete leaf node\n");
    AVLNode *root1 = NULL;
    int data1[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    int n1 = sizeof(data1)/sizeof(data1[0]);
    for (int i = 0; i < n1; i++) {
        root1 = insert_AVLNode(root1, data1[i]);
    }
    printf("  Initial tree: %d nodes, height: %d\n", get_node_count(root1), root1 ? root1->height : 0);
    
    // 删除叶子节点
    root1 = erase_AVLNode(root1, 10);
    printf("  After deleting leaf 10: %d nodes, Balanced: %s\n", 
           get_node_count(root1), is_avl_valid(root1) ? "YES" : "NO");
    
    // 删除只有一个子节点的节点
    root1 = erase_AVLNode(root1, 20);
    printf("  After deleting node with one child (20): Balanced: %s\n", 
           is_avl_valid(root1) ? "YES" : "NO");
    
    // 删除有两个子节点的节点
    root1 = erase_AVLNode(root1, 50);
    printf("  After deleting node with two children (50): Balanced: %s\n", 
           is_avl_valid(root1) ? "YES" : "NO");
    free_avl_tree(root1);
    
    printf("\nTest Case 2.2: Delete root repeatedly\n");
    AVLNode *root2 = NULL;
    int data2[] = {100, 50, 150, 25, 75, 125, 175};
    int n2 = sizeof(data2)/sizeof(data2[0]);
    for (int i = 0; i < n2; i++) {
        root2 = insert_AVLNode(root2, data2[i]);
    }
    
    while (root2 != NULL) {
        int old_key = root2->key;
        root2 = erase_AVLNode(root2, old_key);
        if (root2 && !is_avl_valid(root2)) {
            printf("  ERROR: Tree invalid after deleting %d\n", old_key);
            break;
        }
    }
    printf("  Successfully deleted all nodes including roots\n");
    
    printf("\nTest Case 2.3: Delete non-existent nodes\n");
    AVLNode *root3 = NULL;
    root3 = insert_AVLNode(root3, 10);
    root3 = insert_AVLNode(root3, 20);
    root3 = insert_AVLNode(root3, 30);
    root3 = erase_AVLNode(root3, 99);  // 不存在的节点
    root3 = erase_AVLNode(root3, -5);  // 不存在的节点
    printf("  After deleting non-existent nodes: %d nodes, Balanced: %s\n", 
           get_node_count(root3), is_avl_valid(root3) ? "YES" : "NO");
    free_avl_tree(root3);
}

void test_avl_property() {
    printf("Test Case 3.1: Verify AVL property during rotations\n");
    AVLNode *root = NULL;
    
    // 这个序列会触发各种旋转
    int sequence[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int n = sizeof(sequence)/sizeof(sequence[0]);
    
    for (int i = 0; i < n; i++) {
        root = insert_AVLNode(root, sequence[i]);
        if (!is_avl_valid(root)) {
            printf("  ERROR: AVL property violated after inserting %d\n", sequence[i]);
            printf("  Tree state after error:\n");
            print_avl_structure(root, 0);
            break;
        }
    }
    
    printf("  Final tree: %d nodes, height: %d\n", get_node_count(root), root ? root->height : 0);
    printf("  Theoretical max height for %d nodes in AVL: <= %.2f\n", 
           n, 1.44 * log2(n + 2) - 0.328);
    
    // 验证BST性质
    if (is_bst_valid(root, -1000000, 1000000)) {
        printf("  BST property: VALID\n");
    } else {
        printf("  BST property: INVALID\n");
    }
    
    free_avl_tree(root);
    
    printf("\nTest Case 3.2: Mixed insert/delete while maintaining AVL property\n");
    AVLNode *root2 = NULL;
    
    // 混合操作
    for (int i = 1; i <= 20; i++) {
        root2 = insert_AVLNode(root2, i);
        if (i % 3 == 0) {
            // 每插入3个节点，删除一个
            root2 = erase_AVLNode(root2, i - 1);
        }
        
        if (!is_avl_valid(root2)) {
            printf("  ERROR: AVL property violated at step %d\n", i);
            break;
        }
    }
    printf("  After mixed operations: %d nodes, height: %d, Balanced: %s\n", 
           get_node_count(root2), root2 ? root2->height : 0,
           is_avl_valid(root2) ? "YES" : "NO");
    free_avl_tree(root2);
}

void test_random_operations() {
    printf("Test Case 4.1: Random insertions\n");
    AVLNode *root = NULL;
    int test_size = 50;
    int valid_count = 0;
    
    for (int i = 0; i < test_size; i++) {
        int key = rand() % 1000;
        root = insert_AVLNode(root, key);
        if (is_avl_valid(root)) {
            valid_count++;
        } else {
            printf("  Error after inserting %d\n", key);
            break;
        }
    }
    printf("  Successfully performed %d/%d random insertions\n", valid_count, test_size);
    printf("  Final tree: %d nodes, height: %d\n", get_node_count(root), root ? root->height : 0);
    free_avl_tree(root);
    
    printf("\nTest Case 4.2: Random insertions and deletions\n");
    AVLNode *root2 = NULL;
    int operations = 100;
    valid_count = 0;
    
    for (int i = 0; i < operations; i++) {
        if (rand() % 3 != 0 || get_node_count(root2) < 5) {
            // 70%概率插入，或者树太小就插入
            int key = rand() % 500;
            root2 = insert_AVLNode(root2, key);
        } else {
            // 30%概率删除
            // 随机选择一个已有的节点删除（模拟搜索后删除）
            // 为了简化，我们只删除小于250的值
            root2 = erase_AVLNode(root2, rand() % 250);
        }
        
        if (is_avl_valid(root2)) {
            valid_count++;
        } else {
            printf("  Error at operation %d\n", i);
            break;
        }
    }
    printf("  Successfully performed %d/%d random operations\n", valid_count, operations);
    printf("  Final tree: %d nodes, height: %d\n", get_node_count(root2), root2 ? root2->height : 0);
    free_avl_tree(root2);
}

void test_edge_cases() {
    printf("Test Case 5.1: Empty tree operations\n");
    AVLNode *root = NULL;
    root = erase_AVLNode(root, 100);  // 删除空树中的节点
    root = insert_AVLNode(root, 10);
    root = erase_AVLNode(root, 10);   // 插入后立即删除
    root = erase_AVLNode(root, 10);   // 再次删除
    printf("  Empty tree test completed\n");
    
    printf("\nTest Case 5.2: Single node tree\n");
    root = insert_AVLNode(root, 42);
    printf("  Single node: height=%d, balanced=%s\n", 
           root->height, is_avl_valid(root) ? "YES" : "NO");
    root = erase_AVLNode(root, 42);
    printf("  After deletion: tree is %s\n", root ? "not empty" : "empty");
    
    printf("\nTest Case 5.3: Duplicate insertions\n");
    root = insert_AVLNode(root, 100);
    root = insert_AVLNode(root, 100);  // 重复插入
    root = insert_AVLNode(root, 100);  // 再次重复
    printf("  After inserting 100 three times: %d nodes (should be 1)\n", get_node_count(root));
    free_avl_tree(root);
    
    printf("\nTest Case 5.4: Extreme values\n");
    root = NULL;
    root = insert_AVLNode(root, INT_MAX);
    root = insert_AVLNode(root, INT_MIN);
    root = insert_AVLNode(root, 0);
    printf("  After inserting INT_MAX, INT_MIN, 0: Balanced=%s\n", 
           is_avl_valid(root) ? "YES" : "NO");
    free_avl_tree(root);
}

void test_large_dataset() {
    printf("Test Case 6.1: Large ordered dataset (1000 elements)\n");
    AVLNode *root = NULL;
    int large_size = 1000;
    clock_t start = clock();
    
    for (int i = 1; i <= large_size; i++) {
        root = insert_AVLNode(root, i);
    }
    
    clock_t end = clock();
    double time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("  Inserted %d ordered elements in %.4f seconds\n", large_size, time_used);
    printf("  Tree size: %d nodes, Height: %d\n", get_node_count(root), root ? root->height : 0);
    printf("  AVL property valid: %s\n", is_avl_valid(root) ? "YES" : "NO");
    
    // 验证所有元素都存在
    int all_found = 1;
    for (int i = 1; i <= 100; i++) {  // 只测试100个，避免太慢
        int random_key = rand() % large_size + 1;
        if (!search_AVL(root, random_key)) {
            all_found = 0;
            printf("    ERROR: Key %d not found in AVL tree\n", random_key);
            break;
    }
}
    printf("  Random element check: %s\n", all_found ? "PASSED" : "FAILED");
    
    // 部分删除
    start = clock();
    for (int i = 1; i <= large_size/2; i += 2) {
        root = erase_AVLNode(root, i);
    }
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("  Deleted %d elements in %.4f seconds\n", large_size/2, time_used);
    printf("  After deletions: %d nodes, Balanced: %s\n", 
           get_node_count(root), is_avl_valid(root) ? "YES" : "NO");
    
    free_avl_tree(root);
    
    printf("\nTest Case 6.2: Large random dataset (5000 elements)\n");
    root = NULL;
    large_size = 5000;
    start = clock();
    
    for (int i = 0; i < large_size; i++) {
        root = insert_AVLNode(root, rand() % 10000);
    }
    
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("  Inserted %d random elements in %.4f seconds\n", large_size, time_used);
    printf("  Tree size: %d nodes, Height: %d\n", get_node_count(root), root ? root->height : 0);
    printf("  Height ratio (h/log2n): %.2f (should be < 1.44)\n", 
           root->height / log2(get_node_count(root)));
    
    free_avl_tree(root);
}