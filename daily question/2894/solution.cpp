#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans = "";
        int n = s.size();
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(s[i] == '1')
                cnt++;
        }
        int j=0;
        for(int i=0;i < n-1;i++){
            if(j < cnt-1){
                j++;
                ans += '1';
                continue;
            }
            ans += '0';
        }
        ans += '1';
        return ans;
    }

    
};