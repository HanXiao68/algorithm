//
//  leetcode_169 多数元素.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int > counts;
    int res;    int cur = 0;
        // 遍历里面就一直进行比较次数
        for(int num : nums){
        
        
            counts[num] ++;
            if(counts[num] > cur){
                res = num;
                cur = counts[num];
            }
        }
        return res;
    }
};
