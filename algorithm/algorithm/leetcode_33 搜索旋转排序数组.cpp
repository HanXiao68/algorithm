//
//  leetcode_33 搜索旋转排序数组.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r = nums.size()-1;
        while(l<=r){
            int mid = (l+r)>>1;

            if(target == nums[mid]) return mid;
            // mid先和l比较。 target比较在内层
           // target在左半边。
            if(nums[l] <= nums[mid]){ //注意有 =
                if(target>=nums[l] && target <nums[mid]){
                    r =mid-1;
                }else{
                    l = mid +1;
                }
            }else{
                //target在右半边
                if(target>nums[mid] && target <=nums[r]){
                    l = mid+1;
                }else{
                    r = mid -1;
                }
            }
        }
        return -1;
    }
};
