//
//  leetcode_53 最大子序和.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int pre = 0, maxAns = nums[0];
        for (auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};
