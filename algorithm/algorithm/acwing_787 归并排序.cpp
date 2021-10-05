//
//  acwing——787 归并排序.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/5.
//先分治，再从下往上合并。 用到额外的数组。

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
const int N =1e5+10;
int a[N],temp[N];
int n;

void mergeSort(int a[],int l,int r){
    if(!(l<r)) return;
    
    int mid = (l+r)>>1;
    mergeSort(a, l, mid);
    mergeSort(a, mid+1, r);
    int i = l,j = mid+1;
    int k=0;
    while(i<=mid && j<=r){
        if(a[i] <a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while(i<=mid) temp[k++] = a[i++];
    while(j<=r) temp[k++] = a[j++];
    for(int m = l,j =0;m<=r;m++,j++) a[m] = temp[j];
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    
    mergeSort(a,0,n-1);
    
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    
    return 0;
}















