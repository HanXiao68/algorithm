//
//  leetcode_136 只出现一次的数字.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//

#include <stdio.h>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(auto& x : nums) res ^=x;
        return res;
    }
};
