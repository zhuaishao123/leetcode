#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int,vector<int>> um;
        for(int i = 0;i < n;i++){
            um[nums[i]].push_back(i);
        }
        for(auto [k,v] : um){
            v.push_back(v[0] + n);
            int sub = 0;
            for(int i = 0;i < v.size()-1;i++){
                sub = max(sub,v[i+1]-v[i]);
            }
            ans = min(ans,sub/2);
        }
        return ans;
    }
};