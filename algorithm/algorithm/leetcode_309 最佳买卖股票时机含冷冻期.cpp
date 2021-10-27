//
//  leetcode_309 最佳买卖股票时机含冷冻期.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = 0, rest = 0, hold = INT_MIN;
        for (int p : prices) {
            int pre_sold = sold;
            sold = hold + p;
            hold = max(hold, rest - p);
            rest = max(rest, pre_sold);
        }
        return max(sold, max(rest,hold));
    }
};
