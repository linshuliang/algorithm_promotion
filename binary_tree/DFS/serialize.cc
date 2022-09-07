/* 剑指 Offer II 048. 序列化与反序列化二叉树
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
*/
#include "tree_node.h"
#include <print_vector.h>
#include <queue>
#include <list>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

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

class Codec {
public:
    void rserilize(TreeNode* root, string& ret) {
        if (!root) {
            ret += "null,";
        } else {
            ret += std::to_string(root->val) + ",";
            rserilize(root->left, ret);
            rserilize(root->right, ret);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        rserilize(root, ret);
        return ret;
    }

    TreeNode* rdeserialze(list<string>& arr) {
        if (arr.empty())
            return nullptr;

        if (arr.front() == "null") {
            arr.erase(arr.begin());
            return nullptr;
        }

        TreeNode* root = new TreeNode(std::stoi(arr.front()));
        arr.erase(arr.begin());
        root->left = rdeserialze(arr);
        root->right = rdeserialze(arr);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> arr;
        string temp;
        for (auto& ch : data) {
            if (ch == ',') {
                arr.push_back(temp);
                string().swap(temp);
            } else if (ch == '[' || ch == ']') {
                continue;
            } else {
                temp.push_back(ch);
            }
        }

        if (!temp.empty()) {
            arr.push_back(temp);
            string().swap(temp);
        }

        return rdeserialze(arr);
    }
};

int main() {
    Codec decode;
    string s = "[1,2,3,null,null,4,5]";
    TreeNode* root = decode.deserialize(s);
    cout << decode.serialize(root) << endl;
    vector<vector<int>> level = levelOrder(root);
    cout << endl;
    print(level);
    return 0;
}