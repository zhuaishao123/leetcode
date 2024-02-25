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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pp = p->val;
        int qq = q->val;
        TreeNode* cur = root;
        while(cur){
            int cc = cur->val;
            if(cc == pp || cc == qq)
                return cur;
            if(((cc-pp) ^ (cc-qq)) < 0) 
                return cur;
            if(cc > pp)
                cur = cur->left;
            else
                cur = cur->right;
        }
        return cur;

    }
};