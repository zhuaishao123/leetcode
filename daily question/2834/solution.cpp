#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        int mod = 1e9+7;
        if(n <= (target/2)){
            int ans = 1LL * (1 + n) * n / 2 % mod;
            return ans;
        }else{
            int pre = target/2;
            long long ans = 1LL * (1 + pre) * pre / 2;
            ans += (1LL * target + target + n-pre-1) * (n-pre) / 2;
            ans %= mod;
            return ans;
        }
    }
};