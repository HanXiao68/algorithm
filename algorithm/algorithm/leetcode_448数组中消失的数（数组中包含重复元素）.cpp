//
//  leetcode_448数组中消失的数（数组中包含重复元素）.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        vector<int> temp(nums.size(),0);
        for(int i=1;i<=nums.size();i++){
            temp[i-1] = i;
        }
        for(int x:nums) if(temp[x-1] !=0) temp[x-1] =0;
        for(auto x:temp) {
            // 不能写成!x。只能写x !=0
            if(x !=0)
            res.push_back(x);
            
        }
        return res;
    }
};
