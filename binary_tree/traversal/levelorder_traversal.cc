#include <vector>
#include <queue>
#include <limits.h>
#include "tree_node.h"
#include "build_tree.h"
#include "print_vector.h"
using namespace std;

class Traversal {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root)
            return ret;

        std::queue<TreeNode*> qt;
        qt.push(root);
        while (!qt.empty()) {
            int levelSize = qt.size();
            ret.push_back(vector<int>());
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = qt.front();
                qt.pop();
                ret.back().push_back(node->val);
                if (node->left)
                    qt.push(node->left);
                if (node->right)
                    qt.push(node->right);
            }
        }
        return ret;
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root)
            return ret;

        std::queue<TreeNode*> qt;
        qt.push(root);
        while (!qt.empty()) {
            int levelSize = qt.size();
            ret.push_back(vector<int>());
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = qt.front();
                qt.pop();
                ret.back().push_back(node->val);
                if (node->left)
                    qt.push(node->left);
                if (node->right)
                    qt.push(node->right);
            }
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }

    // https://leetcode.cn/problems/hPov7L/
    // 剑指 Offer II 044. 二叉树每层的最大值
    vector<int> largestValuesInEachLevel(TreeNode* root) {
        if (!root)
            return {};
        vector<int> res;
        queue<TreeNode*> qt;
        qt.push(root);
        while (!qt.empty()) {
            int length = qt.size();
            int max_value = INT_MIN;
            while (length > 0) {
                length--;
                TreeNode* node = qt.front();
                qt.pop();
                max_value = std::max(max_value, node->val);
                if (node->left)
                    qt.push(node->left);
                if (node->right)
                    qt.push(node->right);
            }
            res.push_back(max_value);
        }
        return res;
    }
};

int main() {
    TreeNode* bt = createTestBinaryTree();
    Traversal t;
    vector<vector<int>> res = t.levelOrder(bt);
    print(res);

    std::cout << std::endl;
    vector<vector<int>> bottom = t.levelOrderBottom(bt);
    print(bottom);

    std::cout << std::endl;
    vector<int> largest = t.largestValuesInEachLevel(bt);
    print(largest);

    return 0;
}
