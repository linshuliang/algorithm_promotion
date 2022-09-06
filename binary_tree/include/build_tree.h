#include "tree_node.h"
#include <vector>
#include <unordered_map>
using namespace std;

// https://leetcode.cn/problems/create-binary-tree-from-descriptions/
TreeNode* createBinaryTree(const vector<vector<int>>& descriptions)
{
    unordered_map<int, bool> isRoot;  // 数值对应的节点是否为根节点
    unordered_map<int, TreeNode*> nodes;  // 数值与对应节点的哈希表 
    for(const auto& d: descriptions) {
        int p = d[0];
        int c = d[1];
        bool left = static_cast<bool>(d[2]);
        if(!isRoot.count(p)) {
            isRoot[p] = true;
        }
        isRoot[c] = false;

        // create or update TreeNode
        if(!nodes.count(p)) {
            nodes[p] = new TreeNode(p);
        }
        if(!nodes.count(c)) {
            nodes[c] = new TreeNode(c);
        }

        if(left) {
            nodes[p]->left = nodes[c];
        } else {
            nodes[p]->right = nodes[c];
        }
    }

    // find the root
    int root = -1;
    for(const auto& kv : isRoot) {
        if(kv.second) {
            root = kv.first;
            break;
        }
    }

    return nodes[root];
}

TreeNode* createTestBinaryTree()
{
    vector<vector<int>> descriptions = {
        {20, 15, 1 }, 
        {20, 17, 0}, 
        {50, 20, 1}, 
        {50, 80, 0}, 
        { 80, 19, 1}};

    TreeNode* bt = createBinaryTree(descriptions);
    return bt;
}
