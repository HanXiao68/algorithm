//  acwing_830 单调栈.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/11.
//单调栈的思路精髓：
//    适用的题都是用来找左边或者右边离他最近的大于（或小于）他的数的题。
//    因此，可以使用单调栈。即栈中的数据都是从小到大（或从大到小）---【可以用反证法证明】

#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5+10;
int st[N],n,tt;

int main(){
    cin>>n;
//    在输入的时候，就已经把数组变成了一个单调的数组。（不用管后面的，因为后面会被覆盖。或者理解为，不用管后面的数。只用看前面的比他小的那个数就完了。）
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        while(tt && st[tt] >=x) tt--;
        if(tt) cout<<st[tt]<<" ";
        else cout<<-1<<" ";
        
        st[++tt] = x;
    }
    
    return 0;
}











//const int N =1e5+10;
//int a[N],res[N];
////暴力写法。双层for循环。
// 用数组实现。每次进来数的时候，都与前面的数进行比较。
//int main(){
//    int n;
//    cin>>n;
//    int res[n];
//
//    memset(res,-1,sizeof res);
//    for(int i=0;i<n;i++) cin>>a[i];
//
//    cout<<"-1"<<" "; //第一个数肯定是-1.因为前面没有数了。
//    for(int i=1;i<n;i++){
//        for(int j=i-1;j>=0;j--){
//            if(a[j]<a[i]) {cout<<a[j]<<" ";break;}
//            if(j==0 &&a[j]>=a[i]) cout<<"-1"<<" ";
//        }
//
//    }
//
//    return 0;
//}
