//
//  leetcode_41 缺失的第一个正数.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
// 重点应用了nums[i] =nums[nums[i]]  这句让nums[i] 上的数变换成了 nums[i] == i
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        if(!n) return 1;

        for(auto& x:nums)
            if(x!=INT_MIN) x--;
        for(int i=0;i<n;i++){
            while(nums[i]>=0 &&nums[i] <n && nums[i] !=i &&nums[i]!=nums[nums[i]])
                 swap(nums[i],nums[nums[i]]);
        }

        for(int i=0;i<n;i++)
            if(nums[i] !=i) return i+1;

        return n+1;
    }
};

