#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<Node*> cur{root};
        while(!cur.empty()){
            vector<Node*> tmp;
            ans.emplace_back();
            for(auto node : cur){
                ans.back().push_back(node->val);
                for(auto child : node->children){
                    tmp.push_back(child);
                }
            }
            cur = move(tmp);
        }
        return ans;
    }
};