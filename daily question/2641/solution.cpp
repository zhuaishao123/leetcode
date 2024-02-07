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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<TreeNode*> q;
        q.push_back(root);
        root->val = 0;
        while(!q.empty()){
            vector<TreeNode*> next;
            int sum = 0;
            for(auto node : q){
                if(node->left){
                    next.push_back(node->left);
                    sum += node->left->val;
                }
                if(node->right){
                    next.push_back(node->right);
                    sum += node->right->val;
                }
            }
            for(auto node : q){
                int sub = (node->left ? node->left->val : 0) +
                            (node->right ? node->right->val : 0);
                if(node->left){
                    node->left->val = sum - sub;
                }
                if(node->right){
                    node->right->val = sum - sub;
                }
            }
            q = next;
        }
        return root;
        
    }
};