//
//  jianzhi_40 最小的k个数.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        priority_queue<int> pq;
        for(auto x:input) {
            pq.push(x);
            if(pq.size() > k) pq.pop();
        }
        while(k--){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
        
    }
};
