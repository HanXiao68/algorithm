//
//  acwing_802 区间和.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/9.
//不按照下标的顺序输入。而是指定下标的位置输入。

////丐版写法。求前缀和的时候指定数（100）。当数据大的时候，不能使用。
//#include <stdio.h>
//#include <iostream>
//
//using namespace std;
//int n,m;
//const int N = 1e5+10;
//int a[N],sum[N];
//int main(){
//    cin>>n>>m;
//    for(int i=1;i<=n;i++) {
//        int x,y;
//        cin>>x>>y;
//        a[x]= a[x] + y;
//    }
//    for(int i=1;i<=100;i++){
//        sum[i] =sum[i-1] +a[i];
//    }
//    while(m--){
//        int l,r;
//        cin>>l>>r;
//        int res = sum[r] - sum[l-1];
//        cout<<res<<endl;
//    }
//
//    return 0;
//}

//大数操作。优化版。二分 + pair + 手写unique
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,q;
const int N = 3e5+10;
typedef pair<int,int> PII;
vector<int> alls;
vector<PII> query;
vector<PII> adds;
int a[N],s[N];

int find(int x){
    int l=0;int r = alls.size()-1;
    while(l<r){
        int mid = (l+r) >> 1;
        if(x <= alls[mid] )r = mid;
        else l =mid+1;
    }
    return r+1;
}




int main(){
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        int x,c;
        cin>>x>>c;
        adds.push_back({x,c});
        alls.push_back(x); //将离散化加入的下标映射到一个数组中。方便操作。
        
    }
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        query.push_back({l,r});
        alls.push_back(l);alls.push_back(r);// 加进去了可能会重复（后面再去重）。但是能保证二分的时候能找到l和r。
    }

    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    
    for(auto item:adds){
        int x = find(item.first);//这步会话费很多时间。所以这个用了二分 + 离散化。
        a[x] += item.second;
        
    }
    
    for(int i=1;i<=alls.size();i++) s[i] = s[i-1] +a[i];
    
    for(auto item:query)
    {
        int l = find(item.first);
        int r = find(item.second);
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;
}







