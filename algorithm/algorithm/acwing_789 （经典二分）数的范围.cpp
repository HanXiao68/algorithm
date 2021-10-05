//
//  acwing_789 （经典二分）数的范围.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/5.
//

#include <stdio.h>
#include <iostream>

using namespace std;
const int N = 1e5+10;
int n,q;
int a[N];

int main(){
    cin>>n>>q;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    
    while(q--){
        int k;
        cin>>k;
        
//       二分求下限
        int l =0,r = n-1;
        while(l < r){ //注意没有 = ，按照模板来
            int mid = (l+r) >>1;
            if(a[mid] >=k) r= mid;
            else l = mid+1;
        }
        if(a[r] != k) cout<<"-1 -1"<<endl;
        else{
            cout<<r<<" ";
//          二分求上限
            int l = 0,r = n-1;
            while(l < r){
                int mid = (l+r+1) >>1;
                if(a[mid] <= k) l = mid;
                else r = mid-1;
            }
            cout<<l<<endl;
        }
    }
    
    return 0;
}







