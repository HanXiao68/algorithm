//
//  quick_Sort.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/5.
//

#include <stdio.h>

#include <stdio.h>
#include <iostream>

using namespace std;

const int N = 1e5+10;
int a[N];

void quick_Sort(int a[],int l,int r){
    
    if(!(l < r)) return; //两种写法。这种比较一致。一水的小于。
    
    int i =l-1,j = r+1;
    int x = a[(l+r)>>1];//>> 的优先级大于 +，-
    while(i < j){
        do i++;while(a[i] < x);
        do j--;while(a[j] > x);
        if(i < j) swap(a[i],a[j]);
    }
    quick_Sort(a,l,j);
    quick_Sort(a,j+1,r);
    
    
}
int main(){
    int a[] = {7,6,2,8,1};
    quick_Sort(a,0,4);
    for(int i=0;i<=4;i++) cout<<a[i]<<" ";
}


