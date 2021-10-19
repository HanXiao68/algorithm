//
//  jianzhi_57 和为s的两个数.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//

#include <stdio.h>


class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        int l=0;
        int r = array.size()-1;
        while(l<r){
            int left = array[l];
            int right = array[r];
            if(left+right == sum) return  {left,right};
            if(left+right < sum) l++;
            else r--;
        }
        
        return res;
        
        
        
    }
};
