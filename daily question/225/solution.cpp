#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:

    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(empty()){
            assert(false && "MyStack empty!");
        }
        int n = q1.size();
        for(int i = 0;i < n-1;i++){
            q2.push(q1.front());
            q1.pop();
        }
        int cur = q1.front();
        q1.pop();
        swap(q1,q2);
        return cur;
    }
    
    int top() {
        if(empty()){
            assert(false && "MyStack empty!");
        }
        int n = q1.size();
        for(int i = 0;i < n-1;i++){
            q2.push(q1.front());
            printf("%d",q1.front());
            q1.pop();
        }
        int cur = q1.front();
        q1.pop();
        q2.push(cur);
        swap(q1,q2);
        return cur;        
    }
    
    bool empty() {
        return q1.empty();
    }

    queue<int> q1;
    queue<int> q2;

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */