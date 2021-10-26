//
//  leetcode_42 接雨水.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    int trap(vector<int>& height) {
        
int size  =height.size();
        if(size ==0) return 0;
          int left_max[size],right_max[size];// 左右两个数组，放扫的时候最大的值。
          left_max[0] = height[0];
          for(int i = 1;i<size;i++){
              left_max[i] =max(height[i],left_max[i-1]);
          }

          right_max[size-1] = height[size-1];
          for(int i = size-2;i>=0;i--){
              right_max[i] = max(height[i],right_max[i+1]);
          }
          int res =0;
          for(int i=1;i<size-1;i++){
               res +=min(left_max[i],right_max[i])-height[i];
          }
          return res;


    }
};
