#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int idx = n-1;
        while(idx >= 0){
            long long cur = nums[idx];
            while(idx != 0 && cur >= nums[idx-1]){
                cur += nums[idx-1];
                idx--;
            }
            ans = max(ans,cur);
            idx--;
        }
        return ans;
    }
};