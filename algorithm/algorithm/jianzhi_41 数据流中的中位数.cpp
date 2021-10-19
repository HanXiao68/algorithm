//
//  jianzhi_41 数据流中的中位数.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//

class Solution {
public:
    void Insert(int num) {
        heap_max.push(num);
        if(heap_max.size() >heap_min.size()+1){
            int temp = heap_max.top();
            heap_max.pop();
            heap_min.push(temp);
        }
//         对于奇数个数的堆要严格排序。不能省略。否则报错。
        if(heap_min.size() && heap_max.top()>heap_min.top()){
            int p1 = heap_max.top();
            int p2 = heap_min.top();
            heap_max.pop();
            heap_min.pop();
            heap_max.push(p2);
            heap_min.push(p1);
        }
    }

    double GetMedian() {
    if(heap_max.size() == heap_min.size()) return (heap_max.top() +heap_min.top()) /2.0;
    else return (double) heap_max.top();
    }
priority_queue<int> heap_max;
priority_queue<int,vector<int>,greater<int>> heap_min;
};
