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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<TreeNode*> cur{root};
        while(!cur.empty()){
            vector<TreeNode*> tmp;
            ans.emplace_back();
            for(auto node : cur){
                ans.back().push_back(node->val);
                if(node->left) tmp.push_back(node->left);
                if(node->right) tmp.push_back(node->right);
            }
            cur = move(tmp);
        }
        return ans;
    }
};