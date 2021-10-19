//
//  jianzhi_59 滑动窗口 用deque实现.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        deque<int> q;//双端队列维护有效的下标。
//         删除下标的两种情况：1.下标过期i- q.front() > size 2.当前数< 队尾的数。
       vector<int> res;
      if(num.size() < size) return res;
        for(int i=0;i<num.size();i++){
            if(q.size() && i- q.front()>(size-1)) q.pop_front();
            while(q.size() && num[i]>=num[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            if(i>= size-1) res.push_back(num[q.front()]);
        }
        return res;
    }
};
