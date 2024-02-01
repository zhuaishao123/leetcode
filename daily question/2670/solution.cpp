#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_set<int> us;
        int n = nums.size();
        vector<int> pred(n+1);
        for(int i = n-1;i >= 0;i--){
            if(us.find(nums[i]) == us.end()){
                us.insert(nums[i]);
            }
            pred[i] = us.size();            
        }
        us.clear();
        for(int i = 0;i < n;i++){
            if(us.find(nums[i]) == us.end()){
                us.insert(nums[i]);
            }
            pred[i] = us.size() - pred[i+1];
        }
        pred.pop_back();
        return pred;
    }
};


