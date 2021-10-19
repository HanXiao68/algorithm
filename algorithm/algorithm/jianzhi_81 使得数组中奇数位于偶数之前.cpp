//
//               交换之前一定要加一个判断         if(left<right) swap(array[left],array[right]);         }        return array; jianzhi_81 调整数组中奇数位于偶数之前.cpp
//  algorithm 
//
//  Created by 韩霄 on 2021/10/19.
//

#include <stdio.h>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> reOrderArrayTwo(vector<int>& array) {
        // write code here
        vector<int> res;
        
        int left =0,right = array.size()-1;
        while(left<=right){
             while(array[left]%2 == 1){
                left++;
             }
        while(array[right]%2 ==0) right--;
//             交换之前一定要加一个判断
        if(left<right) swap(array[left],array[right]);
        }
       return array;
    }
};
