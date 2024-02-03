#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<int> pre(n+1);
        for(int i = 0;i < n;i++){
            pre[i+1] = pre[i] + stones[i];
        }
        auto getSum = [=](int i,int j){
            return pre[j+1] - pre[i];
        };
        function<int(int,int)> dfs = [&](int i,int j){
            if(i == j) return dp[i][j] = 0;
            if(dp[i][j] >= 0) return dp[i][j];
            if((n-(j-i+1)) % 2 == 0){
                return dp[i][j] = max(dfs(i,j-1) + getSum(i,j-1),dfs(i+1,j) + getSum(i+1,j));
            }else{
                return dp[i][j] = min(dfs(i,j-1) - getSum(i,j-1),dfs(i+1,j) - getSum(i+1,j));
            }
        };
        return dfs(0,n-1);
    }
};