#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {
        string ans;
        string tmp;
        int i = 0;
        int n = title.size();
        while(i < n){
            if(title[i] == ' '){
                if(tmp.size() > 2)
                    tmp[0] -= 32;
                ans += tmp + " ";
                tmp.clear();
            }else{
                if(title[i] >= 'A' && title[i] <= 'Z')
                    tmp += title[i] + 32;
                else
                    tmp += title[i];
            }
            i++;
        }
        if(tmp.size() > 2)
            tmp[0] -= 32;
        ans += tmp;

        return ans;
    }
};