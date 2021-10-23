//
//  leetcode_435 无重叠区间.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/23.
//

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      if (intervals.empty()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
            return u[1] < v[1];
        });
        for(auto& x:intervals) cout<<x[0]<<" "<<x[1]<<endl;
        int n = intervals.size();
        int right = intervals[0][1];
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] >= right) {
                ++ans;
                right = intervals[i][1];
            }
        }
        return n - ans;
    }
};
