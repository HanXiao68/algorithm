//
//  leetcode_300 最长递增子序列.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
         int n= nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);

        // 求每一个上升子序列的长度
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;//外层每个开头都初始化为1.
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {

                    dp[i] = max(dp[i], dp[j] + 1);//和上一个i的dp[i]相比。
                }
            }
        }
        // 求数组中 上升长度的最大值

        int res = 0;
        for(int i=0;i< n;i++){
            res =max(dp[i],res);
        }
        return res;
    }
};
