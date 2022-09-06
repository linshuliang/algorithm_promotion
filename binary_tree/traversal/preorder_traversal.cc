#include <vector>
#include <stack>
#include "tree_node.h"
#include "build_tree.h"
#include "print_vector.h"
using namespace std;

class Recursion
{
public:
    void preorder(TreeNode* root, vector<int>& res)
    {
        if(!root) return;

        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};

class Simulate
{
public:
    vector<int> preOrderTraversal(TreeNode* root)
    {
        if(!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return res;
    }
};

class Iteration
{
public:
    vector<int> preOrderTraversal(TreeNode *root)
    {
        if(!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(!st.empty() || cur) {
            while(cur) {
                res.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
        return res;
    }
};

int main()
{
    TreeNode* bt = createTestBinaryTree();
    Recursion recur;
    vector<int> res = recur.preorderTraversal(bt);
    print(res);

    Simulate ir;
    vector<int> res2 = ir.preOrderTraversal(bt);
    print(res2);

    Iteration it;
    vector<int> res3 = it.preOrderTraversal(bt);
    print(res3);

    return 0;
}
