//
//  leetcode_155 最小栈.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class MinStack {
public:
   stack<int> st;
    stack<int> min_stack;
    /** initialize your data structure here. */
    MinStack() {
            min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        st.push(x);
        min_stack.push(min(min_stack.top(),x));
    }
    
    void pop() {
        st.pop();
        min_stack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
