//
//  leetcode_312 戳气球.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    int maxCoins(vector<int>& nums) {
            int n = nums.size();
        vector<int> a(n+2,1);
        for(int i=1;i <= n;i++){
            a[i] = nums[i-1];
        }
        vector<vector<int >> f(n+2,vector<int>(n+2));

        for(int len=3;len<=n+2;len++){ //长度
            for(int i =0;i+len-1 <=n+1;i++){ //i的取值范围
                int j = i+len-1;
                for(int k = i+1;k<j;k++){ //k的范围
                    f[i][j] = max(f[i][j],f[i][k] + f[k][j]+a[i]*a[k]*a[j]);
                }

            }

        }

        return f[0][n+1];
    }
};
