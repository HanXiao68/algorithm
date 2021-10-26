//
//  leetcode_55 跳跃游戏.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    bool canJump(vector<int>& nums) {
           int k = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > k) return false; //下标大于 上一次能最远跳的距离的时候，够不着。当前下标 i小于等于 max时，可以往下继续。
        k = max(k, i + nums[i]);
    }
    return true;
    }
};
