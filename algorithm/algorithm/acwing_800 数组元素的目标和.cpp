//
//  acwing_800 数组元素的目标和.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/8.
//

#include <stdio.h>
#include<iostream>

using namespace std;
const int N = 1e5+10;
int a[N],b[N];

int main(){
    int n,m,ans;
    cin>>n>>m>>ans;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<m;j++) cin>>b[j];
    
    for(int i=0,j=m-1;i<n &&j>=0;i++){
        while(a[i] +b[j] >ans) j--;
        if(j>=0 && a[i]+b[j] == ans) cout<<i<<" "<<j;
    }
    return 0;
}



