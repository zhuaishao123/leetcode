#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        vector<int> ans(n,0);
        // if(word[0] == '0') return ans;
        long long cur = 0;
        for(int i = 0;i < n;i++){
            cur = (cur * 10 + word[i] - '0') % m;
            if(cur % m == 0) ans[i] = 1;
        }

        return ans;
    }
};