//
//  leetcode_46 全排列.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> res;
        backstrace(res,nums,0,nums.size());
        return res;
    }

    void backstrace(vector<vector<int>> &res,vector<int>& nums,int first,int len){
        if(first ==len){
            res.push_back(nums);
            return;
        }

        for(int i=first;i<len;i++){
            swap(nums[i],nums[first]);
            
            backstrace(res,nums,first+1,len);
            swap(nums[i],nums[first]);
        }
    }
};
