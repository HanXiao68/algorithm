//
//  leetcode_64 最小路径和.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
         if(grid.size()<0){
            return 0;
        }
        int row =grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        //经典DP
        //初始化第一行和第一列
        dp[0][0] = grid[0][0];
        for(int i=1;i<grid[0].size();i++){
            dp[0][i] = grid[0][i]+dp[0][i-1];
        }
        for(int i=1;i<grid.size();i++){
            dp[i][0] = grid[i][0]+dp[i-1][0];
        }
        //DP推导
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[row-1][col-1];
    }
};
