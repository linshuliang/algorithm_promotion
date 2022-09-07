#ifndef CREATE_BINARY_TREE_
#define CREATE_BINARY_TREE_

#define DEBUG 1

#include "tree_node.h"
#include <iostream>
#include <string>
#include <queue>
#include <list>
using namespace std;

class CREATE_BT {
public:
    TreeNode* levelOrderBuildTree(string);

private:
    list<string> deserialize(string);
};

TreeNode* CREATE_BT::levelOrderBuildTree(string data) {
    deserialize(data);
    return nullptr;
}

list<string> CREATE_BT::deserialize(string data) {
    list<string> arr;
    string temp;
    for (auto& ch : data) {
        if (ch == ',') {
            arr.push_back(temp);
            string().swap(temp);
        } else if (ch == '[' || ch == ']' || ch == ' ') {
            continue;
        } else {
            temp.push_back(ch);
        }
    }

    if (!temp.empty()) {
        arr.push_back(temp);
        string().swap(temp);
    }

#ifdef DEBUG
    for (auto& s : arr) {
        cout << s << " ";
    }
    cout << endl;
#endif

    return arr;
}

#endif