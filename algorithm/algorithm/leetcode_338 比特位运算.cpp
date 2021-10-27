////
////  leetcode_338 比特位运算.cpp
////  algorithm
////
////  Created by 韩霄 on 2021/10/27.
////
//
class Solution {
public:
    vector<int> countBits(int n) {
          vector<int>  res(n+1);
        for(int i =0;i<=n;i++){
            int ans =0;
            int temp = i;
            while(temp >0) {temp=temp&(temp-1);ans++;}
            res[i] = ans;
        }
        return res;


    // vector<int> countBits(int n) {
    //     vector<int> bits(n + 1);
    //     for (int i = 0; i <= n; i++) {
    //         int ones = 0;
    //         int x = i;
    //         while (x > 0) {
    //             x &= (x - 1);
    //             ones++;
    //         }
    //         bits[i] = ones;
    //     }
    //     return bits;
    
    }
};
