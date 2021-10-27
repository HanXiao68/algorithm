//
//  leetcode_128 最长连续序列.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> st;
       for(int i:nums){
           st.insert(i);
       }
       int ans =0;
       for(int i:st){
           if(st.count(i-1)){
        //只把hashset中前一个元素不在nums中的元素作为第一个数查。否则跳过。
               continue;
           }
           //第一个数开始，计数为1. 开始自增
           int count =1;
           while(st.count(i+1)){
               i++;
               count++;
           }
           //每轮都比较出最大的连续序列的个数。
           ans =max(ans,count);
       }
       return ans;
    }
};
