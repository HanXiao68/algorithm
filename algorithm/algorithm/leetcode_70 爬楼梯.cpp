//
//  leetcode_70 爬楼梯.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    int climbStairs(int n) {
        vector<int> f(100000,0);
        f[1] =1;f[2] =2;
        if(n<3) return f[n];
        for(int i=3;i<=n;i++) f[i] = f[i-1] +f[i-2];

        return f[n];
    }
};
