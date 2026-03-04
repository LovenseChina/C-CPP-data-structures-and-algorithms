#include "singleElemSearch.h"
#include "singleElemSearch.cpp"
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// 辅助函数：中序遍历验证 BST 有序性
bool isBST(BSTnode *node, int *prev)
{
    if (!node)
        return true;
    if (!isBST(node->left, prev))
        return false;
    if (node->data <= *prev)
        return false;
    *prev = node->data;
    return isBST(node->right, prev);
}

bool verifyBST(BST T)
{
    int prev = INT_MIN;
    return isBST(T, &prev);
}

// 辅助函数：计算树高度
int treeHeight(BST T)
{
    if (!T)
        return 0;
    return 1 + max(treeHeight(T->left), treeHeight(T->right));
}

// 辅助函数：打印树信息
void printTreeInfo(BST T, const string &label)
{
    cout << "[" << label << "]: ";
    if (!T)
    {
        cout << "Empty tree" << endl;
        return;
    }
    cout << "Height=" << treeHeight(T) << ", ";
    cout << "BST Property: " << (verifyBST(T) ? "Valid" : "INVALID") << endl;
}

// 主测试函数
void test_BST()
{
    cout << "===== Starting BST Implementation Tests =====" << endl;
    cout << "All tests use ASCII characters only" << endl;

    // ===== 测试 1: 空树操作 =====
    cout << "\n*** TEST 1: Empty Tree Operations ***" << endl;
    BST emptyTree = nullptr;
    assert(!find_BST(emptyTree, 5));
    assert(!delete_BST(emptyTree, 5));
    destroy_BST(emptyTree);
    assert(emptyTree == nullptr);
    cout << "Test 1 Passed: Empty tree handled correctly" << endl;

    // ===== 测试 2: 单节点树操作 =====
    cout << "\n*** TEST 2: Single Node Operations ***" << endl;
    BST singleNode = nullptr;
    assert(insert_BST(singleNode, 10));
    assert(singleNode != nullptr);
    assert(singleNode->data == 10);

    // 验证查找
    assert(find_BST(singleNode, 10));
    assert(!find_BST(singleNode, 5));

    // 验证删除
    assert(delete_BST(singleNode, 5) == false); // 删除不存在的元素
    assert(delete_BST(singleNode, 10));
    assert(singleNode == nullptr);

    // 重新插入并销毁
    insert_BST(singleNode, 10);
    destroy_BST(singleNode);
    assert(singleNode == nullptr);
    cout << "Test 2 Passed: Single node operations correct" << endl;

    // ===== 测试 3: 插入和查找 =====
    cout << "\n*** TEST 3: Insertion and Search ***" << endl;
    BST insertTest = nullptr;
    vector<int> vals = {50, 30, 70, 20, 40, 60, 80};

    for (int val : vals)
    {
        assert(insert_BST(insertTest, val));
    }

    // 验证所有值都存在
    for (int val : vals)
    {
        assert(find_BST(insertTest, val));
    }

    // 验证不存在的值
    assert(!find_BST(insertTest, 25));
    assert(!find_BST(insertTest, 55));
    assert(!find_BST(insertTest, 100));

    printTreeInfo(insertTest, "After Insertion");
    destroy_BST(insertTest);
    cout << "Test 3 Passed: Insertion and search work correctly" << endl;

    // ===== 测试 4: 删除叶子节点 =====
    cout << "\n*** TEST 4: Leaf Node Deletion ***" << endl;
    BST leafTest = nullptr;
    for (int val : vals)
        insert_BST(leafTest, val);

    // 删除叶子节点
    assert(delete_BST(leafTest, 20)); // 左叶子
    assert(!find_BST(leafTest, 20));
    assert(leafTest->left->left == nullptr);

    assert(delete_BST(leafTest, 80)); // 右叶子
    assert(!find_BST(leafTest, 80));
    assert(leafTest->right->right == nullptr);

    // 验证剩余节点
    vector<int> remaining = {30, 40, 50, 60, 70};
    for (int val : remaining)
    {
        assert(find_BST(leafTest, val));
    }

    printTreeInfo(leafTest, "After Leaf Deletion");
    destroy_BST(leafTest);
    cout << "Test 4 Passed: Leaf node deletion correct" << endl;

    // ===== 测试 5: 删除单子节点 =====
    cout << "\n*** TEST 5: Single Child Deletion ***" << endl;
    BST singleChildTest = nullptr;
    vector<int> singleChildVals = {50, 30, 70, 40, 60};
    for (int val : singleChildVals)
        insert_BST(singleChildTest, val);

    // 删除只有左子节点的节点
    assert(delete_BST(singleChildTest, 30)); // 有左子节点40
    assert(!find_BST(singleChildTest, 30));
    assert(singleChildTest->left->data == 40);

    // 删除只有右子节点的节点
    assert(delete_BST(singleChildTest, 70)); // 有右子节点60
    assert(!find_BST(singleChildTest, 70));
    assert(singleChildTest->right->data == 60);

    printTreeInfo(singleChildTest, "After Single Child Deletion");
    destroy_BST(singleChildTest);
    cout << "Test 5 Passed: Single child deletion correct" << endl;

    // ===== 测试 6: 删除双子节点 =====
    cout << "\n*** TEST 6: Two Children Deletion ***" << endl;
    BST twoChildrenTest = nullptr;
    vector<int> twoChildrenVals = {50, 30, 70, 20, 40, 60, 80};
    for (int val : twoChildrenVals)
        insert_BST(twoChildrenTest, val);

    // 删除非根的双子节点
    assert(delete_BST(twoChildrenTest, 30)); // 有左右子节点
    assert(!find_BST(twoChildrenTest, 30));
    assert(twoChildrenTest->left->data == 20 || twoChildrenTest->left->data == 40);
    assert(find_BST(twoChildrenTest, 20));
    assert(find_BST(twoChildrenTest, 40));

    // 删除根节点（双子节点）
    assert(delete_BST(twoChildrenTest, 50));
    assert(!find_BST(twoChildrenTest, 50));
    assert(twoChildrenTest->data == 40 || twoChildrenTest->data == 60); // 前驱或后继

    printTreeInfo(twoChildrenTest, "After Two Children Deletion");
    destroy_BST(twoChildrenTest);
    cout << "Test 6 Passed: Two children deletion correct" << endl;

    // ===== 测试 7: 创建函数 =====
    cout << "\n*** TEST 7: Tree Creation from Array ***" << endl;
    int arr[] = {35, 15, 45, 10, 20, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    BST createdTree = batch_create_BST(arr, n);

    // 验证所有元素都存在
    for (int i = 0; i < n; i++)
    {
        assert(find_BST(createdTree, arr[i]));
    }

    // 验证BST属性
    assert(verifyBST(createdTree));

    printTreeInfo(createdTree, "Created Tree");

    // 销毁并验证
    destroy_BST(createdTree);
    assert(createdTree == nullptr);
    cout << "Test 7 Passed: Tree creation from array correct" << endl;

    // ===== 测试 8: 综合测试 =====
    cout << "\n*** TEST 8: Comprehensive Test ***" << endl;
    BST finalTest = nullptr;

    // 阶段1: 插入和混合操作
    vector<int> phase1 = {100, 50, 150, 25, 75, 125, 175};
    for (int val : phase1)
        insert_BST(finalTest, val);

    // 阶段2: 删除各种节点
    assert(delete_BST(finalTest, 25));  // 叶子
    assert(delete_BST(finalTest, 150)); // 双子节点
    assert(delete_BST(finalTest, 100)); // 根节点

    // 阶段3: 插入更多节点
    vector<int> phase3 = {110, 60, 200, 30};
    for (int val : phase3)
        insert_BST(finalTest, val);

    // 阶段4: 验证最终树
    vector<int> shouldExist = {50, 75, 125, 175, 110, 60, 200, 30};
    vector<int> shouldNotExist = {25, 100, 150, 99, 201};

    for (int val : shouldExist)
        assert(find_BST(finalTest, val));
    for (int val : shouldNotExist)
        assert(!find_BST(finalTest, val));

    // 验证BST属性
    assert(verifyBST(finalTest));
    printTreeInfo(finalTest, "Final Tree State");

    // 最终销毁
    destroy_BST(finalTest);
    assert(finalTest == nullptr);
    cout << "Test 8 Passed: Comprehensive test successful" << endl;

    cout << "\n===== All BST Tests Passed Successfully! =====" << endl;
}

int main()
{
    test_BST();
    return 0;
}