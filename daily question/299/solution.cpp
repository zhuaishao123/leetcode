#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        unordered_map<char,int> ums;
        unordered_map<char,int> umg;
        int bull = 0;
        int cow = 0;
        for(int i = 0;i < n;i++){
            if(secret[i] == guess[i])
                bull++;
            else{
                ums[secret[i]]++;
                umg[guess[i]]++;
            }
        }
        for(auto [k,v] : umg){
            if(ums.count(k)){
                cow += min(v,ums[k]);
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};