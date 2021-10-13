//
//  acwing_937 连通块的个数.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/13.
//

#include <stdio.h>
#include<iostream>

using namespace std;

int m;
int n;
const int N =1e5+10;
int sz[N],p[N];

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) {p[i] =i;sz[i] =1;}
    string op;
    while(m--){
        cin>>op;
        if(op =="C"){
            int a,b;
            cin>>a>>b;
            if(find(a) == find(b)) continue; //这句话一定要有，否则sz【】会重复计算。
            sz[find(b)] +=sz[find(a)];
            p[find(a)] = find(b);
        }else if(op =="Q1"){
            int a,b;
            cin>>a>>b;
            if(find(a)==find(b)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }else if(op =="Q2"){
            int a;
            cin>>a;
            cout<<sz[find(a)]<<endl;
        }
    }
    
    return 0;
}
