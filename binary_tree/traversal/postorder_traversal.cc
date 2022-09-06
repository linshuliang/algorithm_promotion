#include <vector>
#include <stack>
#include "tree_node.h"
#include "build_tree.h"
#include "print_vector.h"
using namespace std;

class Recursion
{
public:
    void postorder(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;

        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};

class Iteration
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *prev = nullptr;
        TreeNode *cur = root;

        while (!st.empty() || cur)
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top();
            if (cur->right == nullptr || cur->right == prev)
            {
                res.push_back(cur->val);
                prev = cur;
                cur = nullptr;
                st.pop();
            }
            else
            {
                cur = cur->right;
            }
        }

        return res;
    }
};

class Reverse
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *cur = root;

        while (!st.empty() || cur)
        {
            while (cur)
            {
                res.push_back(cur->val);
                st.push(cur);
                cur = cur->right;
            }

            cur = st.top();
            st.pop();
            cur = cur->left;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

    int main()
    {
        TreeNode *bt = createTestBinaryTree();
        Recursion recur;
        vector<int> res = recur.postorderTraversal(bt);
        print(res);

        Iteration it;
        vector<int> res2 = it.postorderTraversal(bt);
        print(res2);

        Reverse rev;
        vector<int> res3 = rev.postorderTraversal(bt);
        print(res3);

        return 0;
}
