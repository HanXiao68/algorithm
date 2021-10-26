//
//  leetcode_1 两数之和.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     vector<int> res;
        unordered_map<int ,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]] = i;
        }

        for(int i=0;i<nums.size();i++){
            if(m.find(target -nums[i]) !=m.end() && m[target -nums[i]] != i){
                res.push_back(i);
                res.push_back(m[target - nums[i]]);
                break;
            }
                
        }
        return res;
    }
};
