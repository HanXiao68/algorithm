//
//  acwing_786 第k个数.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/5.
//
//以前的写法是：快排完之后，输出a[k-1].
//本题考察的点是：在快排的分支递归范围中做手脚，降低排序中的计算复杂度。

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+10;
int a[N];
int quickSortK(int a[],int l,int r,int k){
    if(!(l<r)) return a[l];
    int i = l-1,j =r+1;
    int x = a[(l+r)>>1];
    while(i < j){
        do i++;while(a[i]<x);
        do j--;while(a[j]>x);
        if(i<j) swap(a[i],a[j]);
    }
    int s1 = j-l+1;//j位置前的个数。包括j。
//    下面的查找范围不能变 （i，j）
    if(k <= s1) return quickSortK(a, l, j, k);
    else return quickSortK(a, j+1, r, k - s1);
    
}
//int main(){
//    int n,k;
//    cin>>n>>k;
//    for(int i=0;i<n;i++) scanf("%d",&a[i]);
//
//    cout<<quickSortK(a,0,n-1,k)<<endl;
//
//    return 0;
//}











