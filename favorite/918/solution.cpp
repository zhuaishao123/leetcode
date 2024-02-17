#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int cur1 = nums[0];
        int cur2 = nums[0];
        int ans1 = nums[0];
        int ans2 = nums[0];
        for(int i = 1;i < n;i++){
            sum += nums[i];
            cur1 = min(cur1 + nums[i], nums[i]);
            cur2 = max(cur2 + nums[i], nums[i]);
            ans1 = min(ans1,cur1);
            ans2 = max(ans2,cur2);
        }
        if(ans2 < 0)
            return ans2;
        return max(sum - ans1, ans2);
    }
};