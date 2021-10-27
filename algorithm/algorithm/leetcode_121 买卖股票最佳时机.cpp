//
//  leetcode_121 买卖股票最佳时机.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {\
        // 遍历一遍，拿到最小值和最大利益
         int res = -1e5;
        int min = 1e5;
        for(int i=0;i<prices.size();i++){
            if(min >=prices[i]){
                min = prices[i];
            }else{
                // 注意res的初始化要是INT_MIN,因为 prices[i]-min会出现负数。
                res = max(res,prices[i]-min);
            }
        }
        if(res>0)
        return res;
        else return 0;
    }
};
