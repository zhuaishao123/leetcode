#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitnum(int x){
        int res = 0;
        while(x > 0){
            if(x % 2)
                res++;
            x /= 2;
        }
        return res;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int res = 0;
        for(int i = 0;i < nums.size();i++){
            if(bitnum(i) == k)
                res += nums[i];
        }
        return res;
    }
};