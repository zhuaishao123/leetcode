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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> nums;
        function<void(TreeNode*)> dfs = [&](TreeNode* root){
            if(root->left) dfs(root->left);
            nums.push_back(root->val);
            if(root->right) dfs(root->right);
        };
        dfs(root);
        int n = nums.size();
        for(auto querie : queries){
            int l = 0;
            int r = n-1;
            int isfind = false;
            while(l <= r){
                int mid = (l+r) >> 1;
                if(nums[mid] == querie){
                    ans.push_back({querie,querie});
                    isfind = true;
                    break;
                }
                if(nums[mid] < querie){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            if(!isfind){
                int mins = l == 0 ? -1 : nums[l-1];
                int maxs = l == n ? -1 : nums[l];
                ans.push_back({mins,maxs});                
            }
        }
        return ans;
    }
};