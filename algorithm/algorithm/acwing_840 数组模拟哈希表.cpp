//
//  acwing_840 数组模拟哈希表.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/16.
//

#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e5+10;
int h[N],e[N],ne[N],idx;

void insert(int x){
    
//    找打映射的数组中的位置。
    int k = (x%N +N) %N; //向上取整
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

void find(int x){
    int k = (x%N + N)%N;
    for(int i=h[k];i != -1;i = ne[i]){
        if(e[i] ==x) {cout<<"Yes"<<endl;return;}
    }
    cout<<"No"<<endl;
}
int main(){
    int n;cin>>n;
//    要设置成-1！！ 0也代表头结点
    memset(h,-1,sizeof h);
    while(n--){
        char op;int x;
        cin>>op>>x;
        if(op == 'I'){
            insert(x);
            
        }else if(op =='Q'){
            find(x);
        }
    }
    return 0;
}




