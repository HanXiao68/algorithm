//
//  leetcode_152 乘积最大子数组.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size(),res =nums[0];
        int preMin =nums[0],preMax = nums[0];

        int temp1 =0,temp2 =0;//最大值最小值

        for(int i=1;i<len;i++){
            // 乘完后，可能会出现负负得正。最小的转成最大的
            temp1 =nums[i] *preMax;
            temp2 =nums[i] *preMin;
            
            preMin = min(min(temp1,temp2),nums[i]);
            preMax = max(max(temp1,temp2),nums[i]);
            res = max(preMax,res);
        }
        return res;
    }
};
