//
//  acwing_829 数组模拟队列.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/11.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int N =1e5+10;
int a[N];
int hh,tt;

int main(){
    int n;
    cin>>n;
    string op;
    while(n--){
        cin>>op;
        if(op =="push"){
            int x;cin>>x;
            a[++tt] = x;
        }else if(op =="pop"){
            hh++;
        }else if(op =="query"){
            cout<<a[hh+1]<<endl;
        }else if(op == "empty"){
            if(hh == tt) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        
    }
    
    return 0;
}
