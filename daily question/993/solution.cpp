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
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int,pair<int,TreeNode*>> um;
        um[root->val].second = nullptr;
        function<void(TreeNode*,int)> dfs = [&](TreeNode* root,int height){
            um[root->val].first = height;
            if(root->left){
                um[root->left->val].second = root;
                dfs(root->left,height+1);
            } 
            if(root->right){
                um[root->right->val].second = root;
                dfs(root->right,height+1);
            }
        };
        dfs(root,0);
        return um[x].first == um[y].first && um[x].second != um[y].second;
    }
};