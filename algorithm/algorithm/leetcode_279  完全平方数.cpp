//
//  leetcode_279  完全平方数.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    int numSquares(int n) {
          // 初始化
        vector<int> dp(n+1);
        // 状态转移  外层是遍历到这个数，内层是 由前面平方数组成的个数。找出最小的
        for(int i =1;i<= n;i++){
            dp[i] = INT_MAX;
            for(int j =1;j*j<= i;j++){
                dp[i] = min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};
