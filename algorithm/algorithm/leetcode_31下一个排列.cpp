//
//  leetcode_31下一个排列.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <=1){
            return;
        }
        int sz = nums.size();

        int idx1 = sz-2;
        for(;idx1 >=0 && nums[idx1] >=nums[idx1+1]; idx1--) ;//从右往左找到不是降序的那个数

        if(idx1 ==-1){ //都是降序。则全部转过来，
            for(int i=idx1+1,j =sz -1;i< j;){
                swap(nums[i++],nums[j--]);
            }
            return ;
        }
        //找出idx1的后面的数中，比idx1大的数里面最小的一个数
        int idx2 = idx1 +1;
        for(int i= idx2; i< sz ;i++){
            if(nums[i]>nums[idx1]) idx2 =i;
            else break;
        }
        swap(nums[idx1],nums[idx2]);
        // idx1后面的数从小到大排
        for(int i=idx1 +1,j =sz-1;i<j;){
            swap(nums[i++],nums[j--]);
        }
    }
};
