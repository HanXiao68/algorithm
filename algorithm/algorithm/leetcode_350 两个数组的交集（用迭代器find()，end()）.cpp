//
//  leetcode_350 两个数组的交集（用迭代器find()，end()）.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int,int> um;
        for(auto x:nums1) um[x]++;

        for(auto x:nums2){
            auto it = um.find(x);
            if(it !=um.end() && --um[x] >=0) res.push_back(x);
        }
        return res;
    }
};
