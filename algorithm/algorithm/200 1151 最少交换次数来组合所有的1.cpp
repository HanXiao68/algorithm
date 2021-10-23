//
//  200 1151 最少交换次数来组合所有的1.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/24.
//

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size();
        int window_len =0;
        for(auto x:data) if(x ==1) window_len++;          //所有1的个数
        int cnt_1 = accumulate(data.begin(), data.begin() + window_len, 0); //第一个窗口内1的个数
      
        int res = window_len - cnt_1;               //第一个窗口内0的个数
        for (int R = window_len; R < n; R ++)       //滑动窗口
        {
            cnt_1 += data[R];                       //进R
            cnt_1 -= data[R - window_len];          //弹L
            int cnt_0 = window_len - cnt_1;         //要交换的次数，就是当前窗口内0的个数
            res = min(res, cnt_0);                  //更新res
        }
        return res;
    }
};
