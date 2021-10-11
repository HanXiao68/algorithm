//
//  滑动窗口.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/11.
//

#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
int n,k;
const int N = 1e6+10;
int a[N],q[N]; //q用来放单调队列

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    
    int hh =0,tt = -1;//窗口的左右端。hh代表左端点，tt代表右端点
//   注意单调队列中存的是下标。便于计算是否过期
    for(int i=0;i<n;i++){
//       删除要两种情况：1，单调队列中左端点过期。2.原始数组中的数小于单调队列中的尾部
        if(hh <= tt && q[hh] < i-k+1) hh++;
        while(hh <=tt && a[q[tt]]>=a[i]) tt--;
        
//        完了后把当前的数加入单调队列
        q[++tt] = i;
       // cout<<"第"<<i<<"个原数组中的数被遍历到"<<" ";
        if(i >= k-1) cout<<a[q[hh]]<<" ";
    }
    puts("");
    
//    下面开始求最大值
     hh =0,tt = -1;//窗口的左右端。hh代表左端点，tt代表右端点
//   注意单调队列中存的是下标。便于计算是否过期
    for(int i=0;i<n;i++){
//       删除要两种情况：1，单调队列中左端点过期。2.原始数组中的数小于单调队列中的尾部
        if(hh <= tt && q[hh] < i-k+1) hh++;
        while(hh <=tt && a[q[tt]]<=a[i]) tt--;
        
//        完了后把当前的数加入单调队列
        q[++tt] = i;
       // cout<<"第"<<i<<"个原数组中的数被遍历到"<<" ";
        if(i >= k-1) cout<<a[q[hh]]<<" ";
    }
    
    return 0;
}


