//
//  leetcode_11 盛水最多的容器.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res =0;

        int l = 0,r = height.size()-1;
        while(l<=r){
            int ans = min(height[l],height[r])*(r-l);

            res = max(res,ans);
            if(height[l]<height[r]) l++;
            else r--;
        }
        return res;
    }
};
