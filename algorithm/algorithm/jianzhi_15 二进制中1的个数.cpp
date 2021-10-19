//
//  jianzhi_二进制中1的个数.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//

class Solution {
public:
     int  NumberOf1(int n) {
         int  count =0;
         while(n!=0)
         {
             n = (n-1)&n;
             count++;
         }
         
         return count;
     }
};

