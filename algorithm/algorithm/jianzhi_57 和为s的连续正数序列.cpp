//
//  jianzhi_57 和为s的连续正数序列.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//

#include <stdio.h>

class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > FindContinuousSequence(int sum) {
        if(sum == 0) return res;
        if(sum < 3) return res;
        int l=1;int r=2; int cur = l+r;
        
        while(r <sum){ //这个范围是冗余的。但没关系
            
            while(cur> sum) { cur-=l;l++;}
            if(cur == sum) {
                vector<int> temp;
                for(int i=l;i<=r;i++)
                    temp.push_back(i);

                res.push_back(temp);
            }

          r++;cur+=r;
        }
        return res;
    }
};
