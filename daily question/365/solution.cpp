#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        stack<pair<int, int>> stk;
        stk.emplace(0, 0);
        auto hash_function = [=](const pair<int, int>& o) {
            return hash<int>()(o.first) ^ hash<int>()(o.second);
        };
        unordered_set<pair<int, int>, decltype(hash_function)> seen(0,hash_function);
        while (!stk.empty()) {
            if (seen.count(stk.top())) {
                stk.pop();
                continue;
            }
            seen.emplace(stk.top());
            auto [remain_x, remain_y] = stk.top();
            stk.pop();
            if (remain_x == z || remain_y == z || remain_x + remain_y == z) {
                return true;
            }
            stk.emplace(x, remain_y);
            stk.emplace(remain_x, y);
            stk.emplace(0, remain_y);
            stk.emplace(remain_x, 0);
            stk.emplace(remain_x - min(remain_x, y - remain_y), remain_y + min(remain_x, y - remain_y));
            stk.emplace(remain_x + min(remain_y, x - remain_x), remain_y - min(remain_y, x - remain_x));
        }
        return false;
    }
};
