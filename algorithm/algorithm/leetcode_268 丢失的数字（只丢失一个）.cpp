//
//  leetcode_268 丢失的数字（只丢失一个）.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size()+1;
        int res =n*(n-1) /2;
        for(auto& x:nums) res -=x;

        return res;
    }
};
