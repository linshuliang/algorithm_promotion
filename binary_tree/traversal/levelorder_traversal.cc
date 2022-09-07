#include <vector>
#include <queue>
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
};

int main() {
    TreeNode* bt = createTestBinaryTree();
    Traversal t;
    vector<vector<int>> res = t.levelOrder(bt);
    print(res);

    std::cout << std::endl;

    vector<vector<int>> bottom = t.levelOrderBottom(bt);
    print(bottom);

    return 0;
}
