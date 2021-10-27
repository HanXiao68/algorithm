//
//  leetcode_338 比特位运算.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    vector<int> countBits(int n) {
          vector<int>  res(num+1);

        res[0] = 0;
        for(int i =1;i <=num;i++){
            if(i & 1){
                res[i] = res[i-1]+1;
            }else{
                res[i] = res[i>>1];
            }
        }
        return res;
    }
};
