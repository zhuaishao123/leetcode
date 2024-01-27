#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minbudget(int n, int k, vector<vector<int>> composition, vector<int>& stock, vector<int>& cost,int c){
        long long budget = INT_MAX;
        for(int i = 0;i < k;i++){
            long long cur = 0;
            for(int j = 0;j < n;j++){
                long long tmp = 1LL * composition[i][j] * c - stock[j];
                if(tmp > 0){
                    cur += tmp * cost[j];
                }
            }
            budget = min(budget , cur);
        }
        return budget;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans = 0;
        int l = 0,r = INT_MAX;
        while(l <= r){
            int mid = (l+r) >> 1;
            long long cur = minbudget(n,k,composition,stock,cost,mid);
            if(cur <= budget){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        } 
        return ans;
    }
};

