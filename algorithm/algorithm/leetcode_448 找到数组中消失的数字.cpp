//
//  leetcode_448 找到数组中消失的数字.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
         int n = nums.size();
        for (auto& num : nums) {
            int x = (num - 1) % n;
            nums[x] += n;
        }
        vector<int> ret;
        for (int i = 1; i <= n; i++) {
            if (nums[i-1] <= n) {
                ret.push_back(i);
            }
        }
        return ret;

    }
};
