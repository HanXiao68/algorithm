//
//  leetcode_56 合并区间.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/23.
//

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> res;
        if(a.size() ==0) return  res;

        sort(a.begin(),a.end());

        for(int i=0;i<a.size();i++){
            int l = a[i][0];int r = a[i][1];

            if(res.size() ==0 ||res.back()[1] < l) res.push_back({l,r});
            else{
                res.back()[1] = max(res.back()[1],r);
            }
        }

        return res;
    }
};
