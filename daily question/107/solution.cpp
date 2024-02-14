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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<TreeNode*> cur{root};
        while(!cur.empty()){
            vector<TreeNode*> tmp;
            ans.push_back(vector<int>{});
            for(auto node : cur){
                ans.back().push_back(node->val);
                if(node->left) tmp.push_back(node->left);
                if(node->right) tmp.push_back(node->right);
            }
            cur = move(tmp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};