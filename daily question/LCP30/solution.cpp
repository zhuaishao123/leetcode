#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int magicTower(vector<int>& nums) {
        long long cur = 1;
        int ans = 0;
        long long delay = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] >= 0)
                cur += nums[i];
            else{
                cur += nums[i];
                pq.push(nums[i]);
                if(cur <= 0){
                    printf("cur < -1\n");
                    if(pq.size() == 0)
                        return -1;
                    else{
                        cur -= pq.top();
                        delay += pq.top();
                        pq.pop();
                        ans++;
                    }
                }
                
            }
        }
        if(cur + delay < 0) return -1;
        return ans;
        
    }
};