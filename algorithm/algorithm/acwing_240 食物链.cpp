//
//  acwing_240 事物链.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/13.
//使用并查集来维护额外信息。

#include <stdio.h>
#include<iostream>

using namespace std;

const int N =50010;
int p[N];//维护父节点和块根节点的关系
int d[N];//维护到块根节点的距离信息


int find(int x){
    if(p[x] !=x)
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

//d[x]是该点到上一个节点的距离。
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) p[i]=i;
    
    int res =0;
    while(k--){
        int t,x,y;
        cin>>t>>x>>y;
        
        if(x>n || y>n) res ++;
        else{
            int px = find(x);
            int py = find(y);
            if(t == 1)
            {
//           在同一个联通块中
                
                if(px ==py &&(d[x]-d[y])%3 !=0) res++;
                else if(px !=py)
                {
                    p[px] =py;//连城一块
                    d[px] = d[y]-d[x];
                }
            }
            else{
                if(px ==py &&(d[x]-d[y]-1)%3!=0) res++;
                else if(px !=py){
                    p[px] = py;
                    d[px] = d[y]+1-d[x];
                }
            }
        }
    }
    
    cout<<res<<endl;
    return 0;
}
