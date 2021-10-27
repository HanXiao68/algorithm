//
//  leetcode_322 零钱兑换DP.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    int coinChange(vector<int>& coins, int m) {
        // 是一个完全背包问题。不能用贪心。
        vector<int> f(m+1,1e8);//表示个数。
        f[0] = 0;
        for(auto x:coins){
            for(int j = x;j<=m;j++){
                f[j] = min(f[j],f[j-x]+1);
            }
        }
        if(f[m] ==1e8) return -1;
        return f[m];
    }
};
