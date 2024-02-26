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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return 0;
        int s = 0;
        s += rangeSumBST(root->left,low,high);
        s += rangeSumBST(root->right,low,high);
        if(root->val <= high && root->val >= low) s += root->val;
        return s;
    }
};