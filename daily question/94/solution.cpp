#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        unordered_set<TreeNode*> vis;
        stack<TreeNode*> s;
        if(!root) return {};
        s.push(root);
        while(!s.empty()){
            auto cur = s.top();
            if(cur->left && !vis.count(cur->left)){
                s.push(cur->left);
                continue;
            }
            ans.push_back(cur->val);
            vis.insert(cur);
            s.pop();
            if(cur->right && !vis.count(cur->right))
            {
                s.push(cur->right);
                continue;
            }
        }
        return ans;
    }
};