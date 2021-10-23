//
//  leetcode_739 每日温度（单调栈）.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/23.
//

class Solution {
public:
    
    vector<int> dailyTemperatures(vector<int>& a) {
        vector<int> res(a.size());

        stack<int> st;
        for(int i=0;i<a.size();i++){
            while(!st.empty() && a[i] >a[st.top()] ){
                res[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
