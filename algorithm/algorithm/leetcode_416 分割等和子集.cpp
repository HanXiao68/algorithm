//
//  leetcode_416 分割等和子集.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
     bool canPartition(vector<int>& nums) {
     
        int sum = 0;
        
        
        for (auto x : nums)  sum += x;
        if (sum % 2 !=0) return false;
        int n = nums.size();

        //求背包价值为sum/2是否存在
        sum = sum / 2;
        vector<vector<bool> > dp(n+1,vector<bool> (sum+1,false));

        for (int i = 0; i <= n;i++) {
            dp[i][0] = true;

        }
        for (int i = 1; i <= n;i++) {
            for (int j = 1; j <= sum;j++ ) {
                if (j - nums[i - 1] < 0)
                    dp[i][j] = dp[i-1][j];
            
                else {
                    dp[i][j] = dp[i - 1][j] | dp[i-1][j-nums[i-1]]; //能装下的时候有两种选择。
                }
            }
        }

        return dp[n][sum];
    }
};
