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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        function<TreeNode*(int,int,int,int)> dfs = 
            [&](int inl,int inr,int pol,int por) -> TreeNode*
        {
            if(inl > inr) return nullptr;
            TreeNode* cur = new TreeNode(postorder[por]);
            int idx = inl;
            while(inorder[idx] != postorder[por]){
                idx++;
            }
            int tmp = idx - inl;
            cur->left = dfs(inl,inl+tmp-1,pol,pol+tmp-1);
            cur->right = dfs(inl+tmp+1,inr,pol+tmp,por-1);
            return cur;
        };
        return dfs(0,n-1,0,n-1);
    }
};