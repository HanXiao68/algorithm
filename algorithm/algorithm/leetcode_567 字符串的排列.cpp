//
//  leetcode_567 字符串的排列.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/11/1.
//

#include <stdio.h>
class Solution {
public:
    unordered_map<char,int> S1,S2;
    int cnt;
    bool check(char c){
        if(S1.count(c) && S1[c]==S2[c]) return true;
        return false;
    }
    bool checkInclusion(string s1, string s2) {
        // 用两个哈希表，表示原始s1中的柱子状态。s2表示在双指针移动过程中的柱子的状态变化。cnt代表柱子相同的个数。
        
        for(auto x:s1) S1[x]++;
        for(int i=0,j=0,cnt=0;i<s2.size();i++){
            // 判断双指针中右端点i移动的状态。
            if(check(s2[i])) cnt--;
            S2[s2[i]]++;
            if(check(s2[i])) cnt++;
            // 右端点移动了。那么就肯定有一个柱子要不相等
            if(i-j >=s1.size()){
                if(check(s2[j])) cnt--;
                S2[s2[j]] --;
                if(check(s2[j])) cnt++;
                j++;
            }
            if(cnt== S1.size()) return true;
        }
            return false;
    }
    
};
