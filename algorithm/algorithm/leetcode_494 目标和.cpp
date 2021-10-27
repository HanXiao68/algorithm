//
//  leetcode_494 目标和.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//回溯

class Solution {
public:
    int count = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums, target, 0, 0);
        return count;
    }

    void backtrack(vector<int>& nums, int target, int index, int sum) {
        if (index == nums.size()) {
            if (sum == target) {
                count++;
            }
        } else {
            backtrack(nums, target, index + 1, sum + nums[index]);
            backtrack(nums, target, index + 1, sum - nums[index]);
        }
    }

    
};
