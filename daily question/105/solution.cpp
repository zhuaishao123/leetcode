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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        function<TreeNode*(vector<int>,vector<int>)> dfs 
            = [&](vector<int> pre,vector<int> order) ->TreeNode*{
                if(pre.empty()) return nullptr;
                TreeNode* cur = new TreeNode(pre[0]);
                int idx = 0;
                vector<int> pre_left;
                vector<int> pre_right;
                vector<int> order_left;
                vector<int> order_right;
                while(order[idx] != pre[0]){
                    idx++;
                }
                for(int i = 0;i < pre.size() - 1;i++){
                    if(i < idx){
                        pre_left.push_back(pre[i+1]);
                        order_left.push_back(order[i]);                        
                    }else{
                        pre_right.push_back(pre[i+1]);
                        order_right.push_back(order[i+1]);
                    }
                }
                cur->left = dfs(pre_left,order_left);
                cur->right = dfs(pre_right,order_right);
                return cur;
            };  
        
        return dfs(preorder,inorder);
    }
};