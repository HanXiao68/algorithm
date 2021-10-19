////
////  leetcode_347 前k个高频元素.cpp
////  algorithm
////
////  Created by 韩霄 on 2021/10/19.
////
//
//class Solution {
//public:
//    static bool cmp(pair<int,int>& x,pair<int,int>&y){
//        return x.second >y.second;
//    }
//    vector<int> topKFrequent(vector<int>& nums, int k) {
//        vector<int> res;
//
//        unordered_map<int,int> um;
//
//        for(auto x:nums) um[x]++;
////定义了一个vector a，元素装的是 um 中的 PII类型元素。
//       vector<pair<int,int>> a(um.begin(),um.end());
//       sort(a.begin(),a.end(),cmp);
//
//        for(int i=0;i<k;i++)
//            res.push_back(a[i].first);
//        return res;
//    }
//};
