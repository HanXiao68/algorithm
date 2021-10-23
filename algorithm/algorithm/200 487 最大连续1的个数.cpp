//
//  200 487 最大连续1的个数.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/23.
//

//暴力求解每个区间。然后比较大小。
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=(int)nums.size(),ans=0;
        vector<int>pre(n,0),suff(n,0);
        for (int i=0;i<n;++i){
            if (i) pre[i]=pre[i-1];
            if (nums[i]) pre[i]++;
            else pre[i]=0;
            ans=max(ans,pre[i]);
        }
        for (int i=n-1;i>=0;--i){
            if (i<n-1) suff[i]=suff[i+1];
            if (nums[i]) suff[i]++;
            else suff[i]=0;
        }
        for (int i=0;i<n;++i)if(!nums[i]){
            int res=0;
            if (i>0) res+=pre[i-1];
            if (i<n-1) res+=suff[i+1];
            ans=max(ans,res+1);
        }
        return ans;
    }
};

//dp解法。

定义 dp[i][0]dp[i][0] 为考虑到以 ii 为结尾未使用操作将 [0,i][0,i] 某个 00 变成 11 的最大的连续 11 的个数，dp[i][1]dp[i][1] 为考虑到以 ii 为结尾使用操作将 [0,i][0,i] 某个 00 变成 11 的最大的连续 11 的个数。则我们可以列出转移式：

public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=(int)nums.size(),ans=0,dp0=0,dp1=0;
        for (int i=0;i<n;++i){
            if (nums[i]){
                dp1++;
                dp0++;
            }
            else{
                dp1=dp0+1;
                dp0=0;
            }
            ans=max(ans,max(dp0,dp1));
        }
        return ans;
    }
};

