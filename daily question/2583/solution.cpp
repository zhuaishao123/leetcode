#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    using LL = long long;
    long long kthLargestLevelSum(TreeNode* root, int k) {
        LL ans = 0;
        priority_queue<LL ,vector<LL>,greater<LL>> pq;
        vector<TreeNode*> cur = {root};
        while(!cur.empty()){
            vector<TreeNode*> tmp;
            LL sum = 0;
            for(auto node : cur){
                sum += node->val;
                if(node->left) tmp.push_back(node->left);
                if(node->right) tmp.push_back(node->right);
            }
            if(pq.size() < k){
                pq.push(sum);
            }else{
                if(sum > pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }
            cur = move(tmp);

        }
        return pq.size() == k ? pq.top() : -1;
        
    }
};