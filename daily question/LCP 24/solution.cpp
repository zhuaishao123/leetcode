#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numsGame(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++){
            nums[i] -= i;
        }
        vector<int> ans(nums.size());
        priority_queue<int,vector<int>,greater<int>> upper;
        priority_queue<int,vector<int>,less<int>> lower;
        lower.push(INT_MIN);
        upper.push(INT_MAX);
        long long mod = 1e9 + 7;
        long long lowerSum = 0;
        long long upperSum = 0;
        auto swap = [&](){
            int x = upper.top();
            int y = lower.top();
            upper.pop();
            lower.pop();
            upper.push(y);
            lower.push(x);
        };
        for(int i = 0;i < nums.size();i++){
            if(i % 2 == 0){
                lower.push(nums[i]);
                lowerSum += nums[i];
                if(lower.top() > upper.top()){
                    lowerSum += upper.top() - lower.top();
                    upperSum -= upper.top() - lower.top();
                    swap();
                }
                ans[i] = (upperSum - lowerSum + lower.top()) % mod; 
            }else{
                upper.push(nums[i]);
                upperSum += nums[i];
                if(lower.top() > upper.top()){
                    lowerSum += upper.top() - lower.top();
                    upperSum -= upper.top() - lower.top();
                    swap();                    
                }
                ans[i] = (upperSum - lowerSum) % mod; 
            }  
        }
        return ans;
    }
};