#include <vector>
#include <stack>
#include "tree_node.h"
#include "build_tree.h"
#include "print_vector.h"
using namespace std;

class Recursion
{
public:
    void inorder(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;
        
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};

class Iteration
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (!st.empty() || cur)
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};

int main()
{
    TreeNode *bt = createTestBinaryTree();
    Recursion recur;
    vector<int> res = recur.inorderTraversal(bt);
    print(res);

    Iteration it;
    vector<int> res3 = it.inorderTraversal(bt);
    print(res3);

    return 0;
}
