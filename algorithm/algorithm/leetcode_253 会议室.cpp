//
//  leetcode_253 会议室.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/5.
//

//每一个区间代表一次会议的开始时间和结束时间。求最少需要多少会议室。
//示例 1:
//输入: [[0, 30],[5, 10],[15, 20]]
//输出: 2
//
//示例 2:
//输入: [[7,10],[2,4]]
//输出: 1

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class solution{
    
public:
    int minRooms(vector<vector<int>>& intervals){
        if(intervals.empty()) return 0;
        sort(intervals.begin(),intervals.end(),[&](auto a,auto b){
            if(a[0]==b[0])
                return a[1]<b[1];
            else return a[0]<b[0];
        });
        
        priority_queue<int,vector<int>,greater<int>> q;//优先队列
//        [i][0] 代表第i个会议的开始时间；[i][1]代表结束时间。
        q.push(intervals[0][1]);
//        遍历每个会议(从第二个开始，因为第一个在上一句已经push进去了)
        for(int i=1;i<intervals.size();i++){
//            两个区间没有重叠（边界相等不算），就可以共用一个。因此弹出一个区间
            if(intervals[i][0] >= q.top()){
                q.pop();
            }
//            有重叠的就得重开一个会议室。
            q.push(intervals[i][1]);
        }
        return q.size();
    }

};
int main(){
    
    vector<vector<int > > a = {
//        {0,30},{5,10},{15,20}
        {7,10},{2,4}
    };
    solution s;
    cout<<s.minRooms(a)<<endl;
    return 0;
}






