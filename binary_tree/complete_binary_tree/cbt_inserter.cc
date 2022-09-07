#include <queue>
#include "tree_node.h"
using namespace std;

class CBTInserter {
public:
    CBTInserter(TreeNode* root);
    int insert(int v);
    TreeNode* get_root() {
        return this->root;
    }

private:
    queue<TreeNode*> candidate;
    TreeNode* root;
};

CBTInserter::CBTInserter(TreeNode* root) {
    this->root = root;
    queue<TreeNode*> qt;
    qt.push(root);
    while (!qt.empty()) {
        TreeNode* node = qt.front();
        qt.pop();
        if (node->left)
            qt.push(node->left);
        if (node->right)
            qt.push(node->right);
        if (!(node->left && node->right)) {
            candidate.push(node);
        }
    }
}

int CBTInserter::insert(int val) {
    TreeNode* child = new TreeNode(val);
    TreeNode* node = candidate.front();
    int ret = node->val;
    if (!node->left) {
        node->left = child;
    } else  // if(!node->right)
    {
        node->right = child;
        candidate.pop();
    }
    candidate.push(child);
    return ret;
}
