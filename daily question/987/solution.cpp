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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>> nodes;
        function<bool(tuple<int,int,int>,tuple<int,int,int>)> cmp = [](auto a,auto b){
            if(get<0>(a) != get<0>(b)){
                return get<0>(a) < get<0>(b);
            }
            if(get<1>(a) != get<1>(b)){
                return get<1>(a) < get<1>(b);
            }
            if(get<2>(a) != get<2>(b)){
                return get<2>(a) < get<2>(b);
            }
            return true;
        };
        function<void(TreeNode*,int,int)> dfs = [&](TreeNode* root,int row,int col){
            if(!root) return;
            nodes.emplace_back(col,row,root->val);
            dfs(root->left, row + 1, col - 1);
            dfs(root->right, row + 1, col + 1);
        };
        dfs(root,0,0);
        sort(nodes.begin(),nodes.end(),cmp);
        vector<vector<int>> ans;
        int lastcol = INT_MIN;
        for(auto [col,row,value] : nodes){
            if(col != lastcol){
                lastcol = col;
                ans.push_back(vector<int>{});
            }
            ans.back().push_back(value);
        }
        return ans;
    }
};