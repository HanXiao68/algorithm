//
//  leetcode_217 判断是否存在重复的数.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int > um;
        for(auto x:nums) {
            um[x]++;
            if(um[x]>1) return true;
        }
        return false ;
    }
};
