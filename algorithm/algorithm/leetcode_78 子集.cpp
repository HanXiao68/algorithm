//
//  leetcode_78 子集.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int>temp;
    vector<vector<int>> subsets(vector<int>& nums) {
        
        if(nums.size() ==0) return res;
        helper(nums,0);
        return res;
    }
    void helper(vector<int>& nums,int idx){
        res.push_back(temp); //所有长度的痘要打出来。
//        只打出长度是nums长度的数。
//        if(idx ==nums.size())
//        {
//            res.push_back(temp);return;
//        }
        for(int i=idx;i<nums.size();i++){
            temp.push_back(nums[i]);
            helper(nums, i+1);
            temp.pop_back();
        }
    }
};
