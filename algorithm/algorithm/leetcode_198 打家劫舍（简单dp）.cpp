//
//  leetcode_198 打家劫舍（简单dp）.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    int rob(vector<int>& nums) {
         //边界条件
        if(nums.size() ==0) return 0;
        if(nums.size() ==1) return nums[0];
        // 初始化dp数组
        vector<int> dp(nums.size() +1);
        dp[0] =nums[0];
        dp[1] =max(nums[0],nums[1]);

        // 状态转移方程 dp[i]= max(dp[i-2]+nums[i],dp[i-1])
        for(int i =2 ;i<nums.size();i++){
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        }

        return dp[nums.size()-1];
    }
};
