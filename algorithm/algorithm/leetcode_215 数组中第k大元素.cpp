//
//  leetcode_215 数组中第k大元素.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         priority_queue<int,vector<int>,greater<int>> pq;
        for(auto& x : nums){
            if(pq.size()>k && pq.top() >= x) continue;
            else
                pq.push(n);
                if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
