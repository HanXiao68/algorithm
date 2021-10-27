//
//  leetcode_406 根据身高重建队列.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),
           //重点在让写正则。
            [](const vector<int>& a, const vector<int>& b) {
            if (a[0] > b[0]) return true;
            if (a[0] == b[0] && a[1] < b[1]) return true;
            return false;
        });
        
        vector<vector<int>> res;
        for (auto& e : people) {
            // insert函数
            res.insert(res.begin() + e[1], e);//在这个位置插入e。
        }
        return res;
    }
};
