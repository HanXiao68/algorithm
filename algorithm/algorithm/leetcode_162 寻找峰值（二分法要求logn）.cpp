//
//  leetcode_162 寻找峰值（二分法要求logn）.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//

#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0,r = nums.size()-1;
        while(l < r){
            int mid = (l+r) >>1;
            if(nums[mid] > nums[mid+1]) r = mid;
            else l = mid+1;
        }
        return l;//这里返回l 和r都一样。 最后的l == r
    }
};
