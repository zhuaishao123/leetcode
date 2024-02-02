#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        function<bool(tuple<int,int> a,tuple<int,int> b)> comp = [](tuple<int,int> a,tuple<int,int> b){
            return get<0>(a) < get<0>(b);
        };
        // auto comp = [](tuple<int,int> a,tuple<int,int> b){
        //     return get<0>(a) < get<0>(b);
        // };
        priority_queue<tuple<int,int>,vector<tuple<int,int>>,decltype(comp)> pq(comp);
        for(int i = 0;i < n;i++){
            pq.emplace(aliceValues[i] + bobValues[i] , i);
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(i % 2 == 0){
                ans += aliceValues[get<1>(pq.top())];
            }else{
                ans -= bobValues[get<1>(pq.top())];
            }
            pq.pop();
        }
        if(ans > 0) return 1;
        if(ans < 0) return -1;
        return 0;
    }
};