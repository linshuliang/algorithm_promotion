#include "tree_node.h"
#include "create_binary_tree.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Solution {
public:
    int dfs(TreeNode* root, int prevSum) {
        if (root == nullptr) {
            return 0;
        }
        int sum = prevSum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return sum;
        } else {
            return dfs(root->left, sum) + dfs(root->right, sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};

int main() {
    string input = "[4,91,0,525,null,1]";
    CREATE_BT create;
    TreeNode* root = create.levelOrderBuildTree(input);

    Solution sol;
    cout << sol.sumNumbers(root) << endl;

    return 0;
}
