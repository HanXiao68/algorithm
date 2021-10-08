//
//  acwing_797 差分.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/8.
//

#include <stdio.h>
#include <iostream>
const int N = 1e5+10;
int a[N],b[N];
int n,q;
using namespace std;

void insert(int l,int r,int c){
    b[l] +=c;
    b[r+1] -=c;
}
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        insert(i,i,a[i]);
    }
    
    while(q--)
    {
        int l,r,c;
        cin>>l>>r>>c;
        insert(l,r,c);
    }
    for(int i=1;i<=n;i++) b[i] +=b[i-1];
    for(int i=1;i<=n;i++) cout<<b[i]<<" ";
    return 0;
}


