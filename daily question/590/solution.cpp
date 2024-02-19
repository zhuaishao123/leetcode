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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        unordered_set<Node*> vis;
        if(!root) return {};
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty()){
            auto node = stk.top();
            if(vis.count(node)){
                ans.push_back(node->val);
                stk.pop();
            }else{
                vis.insert(node);
                for(auto it = node->children.rbegin();it != node->children.rend();it++){
                    stk.push(*it);
                }
            }
        }
        return ans;
    }
};