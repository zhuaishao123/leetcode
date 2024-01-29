#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void backtrace(vector<int>& nums, int idx, vector<int>& cur, vector<int>& vis){
        if(idx == nums.size()){
            ans.push_back(cur);
            return ;
        }
        for(int i = 0;i < nums.size();i++){
            if(!vis[i]){
                cur.push_back(nums[i]);
                vis[i] = 1;
                backtrace(nums, idx+1, cur, vis);
                vis[i] = 0;
                cur.pop_back();
            }
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n,0);
        vector<int> cur;
        backtrace(nums, 0, cur, vis);
        return ans;
    }
};