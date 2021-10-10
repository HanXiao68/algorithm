//
//  acwing_803区间合并.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/9.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


typedef pair<int,int> PII;
int n;
vector<PII> segs;
vector<PII> res;
int main(){
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        segs.push_back({l,r});
        
    }
    
    sort(segs.begin(),segs.end());
    int st=-2e9,ed = -2e9;//必须分别初始化。不能int st,ed = -2e9;
    for(auto x: segs){
        if(ed <x.first){
            if(st !=-2e9) res.push_back({st,ed});
            st = x.first;ed = x.second;
        }
        else ed = max(ed,x.second);
    }
//    把最后一个满足条件的加入res中。不要这句，会少最后一个区间。
    if(st !=-2e9) res.push_back({st,ed});
    for(auto x : res) cout<<x.first<<" "<<x.second<<endl;
    cout<<res.size()<<endl;
    return 0;
}
