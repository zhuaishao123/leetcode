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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        function<TreeNode*(int,int,int,int)> dfs = 
            [&](int pl,int pr,int pol,int por)->TreeNode*
            {
                if(pl > pr) return nullptr;
                TreeNode* cur = new TreeNode(preorder[pl]);
                if(pl == pr) return cur;
                int idx = 0;
                while(postorder[pol+idx] != preorder[pl+1]){
                    idx++;
                }
                cur->left = dfs(pl+1,pl+1+idx,pol,pol+idx);
                cur->right = dfs(pl+2+idx,pr,pol+idx+1,por);
                return cur;
            };
        return dfs(0,n-1,0,n-1);
    }
};