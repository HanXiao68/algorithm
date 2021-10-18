//
//  leetcode_34 在排序数组中查找元素的第一个和最后一个位置.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.size() ==0) return {-1,-1};
        int l=0,r = nums.size()-1;
        while(l < r){
            int mid = (l+r)>>1;
            if(nums[mid] >= target) r = mid;
            else l = mid+1;
        }
        //cout<<r<<endl;
        if(nums[r] !=target) {return {-1,-1};}
        res.push_back(r);

        l = 0,r = nums.size()-1;
        while(l < r){
            int mid = (l+r+1)>>1;
            if(nums[mid] <= target) l = mid;
            else r = mid-1;
        }
        //cout<<l<<endl;
        res.push_back(l);
        reverse(nums.begin(),nums.end());
        return res;
    }
};
