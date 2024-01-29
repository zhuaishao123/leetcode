#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n1 = ring.size();
        int n2 = key.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n2,vector<int>(n1,-1));
        for(int i = 0;i < n1;i++){
            if(ring[i] == key[0]){
                dp[0][i] = min(i,n1-i);
            }      
        }
        for(int i = 1;i < n2;i++){
            for(int j = 0;j < n1;j++){
                if(ring[j] == key[i]){
                    int tmp = INT_MAX;
                    for(int z = 0;z < n1;z++){
                        if(dp[i-1][z] != -1){
                            tmp = min(tmp , dp[i-1][z] + min(abs(z-j),n1 - abs(z-j))) ;
                        }
                    }
                    dp[i][j] = tmp;
                }
            }
        }
        for(int i = 0;i < n1;i++){
            if(dp[n2-1][i] != -1)
                ans = min(ans,dp[n2-1][i]);
        }

        return ans + n2;
        
    }
};