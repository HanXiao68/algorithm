//
//  acwing_842 数字排列.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/20.
//

#include<iostream>

using namespace std;
int n;
const int N = 10;
bool st[N];
int path[N];
void dfs(int u){
    if(u>n)
    {
        for(int i=1;i<=n;i++) cout<<path[i]<<" ";
        cout<<endl;
        return;
    }
    
    for(int i=1;i<=n;i++){
        if(!st[i]){
            
        st[i] = true;
        path[u] = i; //在第u个位置上放i
        dfs(u+1);
        st[i] = false;
        path[u] =0;
        }
    }
}
int main(){
    cin>>n;
    dfs(1);
    
    return 0;
}
