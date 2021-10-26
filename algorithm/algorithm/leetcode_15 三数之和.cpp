//
//  leetcode_15 三数之和.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         // 解法：暴力双重循环。或者  哈希表。
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++)
        {
            // 对于数组的每一个数
            if(nums[i]>0) break; //排好序的。如果这个数是正数。那后面的数都比他大。就不可能是和为0.
            //考虑相同元素跳过，不在重复算。
            if(i>0&&nums[i] == nums[i-1])
                continue;
            // 按住一个数，给出其他两数之和，进行二分查找 和为target
            int target = 0-nums[i];
            
            int j = i+1,k = nums.size()-1;
            // 双指针。算两数之和。
            while(j<k)
            {
                if(nums[j]+nums[k] == target)
                {
                    res.push_back({nums[i],nums[j],nums[k]});

                     while(j<k&&nums[j+1] == nums[j]) j++;
                     while(j<k&&nums[k-1] == nums[k]) k--;
                    j++;k--;
                }

                else if(nums[j]+nums[k]<target)
                    j++;
                else
                    k--;
            }
        }
        return res;
    
    }
};
