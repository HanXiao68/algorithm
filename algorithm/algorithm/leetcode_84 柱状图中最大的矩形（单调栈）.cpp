//
//  leetcode_84 柱状图中最大的矩形（单调栈）.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int ans = 0;
        vector<int> st;
        // 头尾插上0.方便计算边缘部分
        a.insert(a.begin(),0);
        a.push_back(0);

        for(int i =0;i<a.size();i++){
            // 单调栈放左边最大和右边最大的下标。找到左右最大的边界
            while(!st.empty() && a[st.back()] > a[i]){
                int cur = st.back();
                st.pop_back();
                int left = st.back() +1;
                int right = i-1;
                ans = max(ans,(right - left+1)* a[cur]);
            }
            st.push_back(i);
        }
    return ans;
    }
};
