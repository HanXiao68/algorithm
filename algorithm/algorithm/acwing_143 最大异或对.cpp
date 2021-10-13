//
//  acwing_143 最大异或对.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/13.
//把每个数看成是长度为31位的二进制数。使用trie树存储二进制数。每一个节点非0即1.
//暴力是两层for循环
//for(){
//    for(){
//        res = max(res, str1^str2);
//    }
//}
//trie是优化了内层循环。先查找（与当前异或最大的结果）再插入。（先插入再查找也一样）


//注意：该加括号就加括号！！不同的编译器结果不同。但是加了括号就没错！！
#include <stdio.h>
#include <iostream>

using namespace std;
const int N= 1e5+10,M = 31*N; //最大N个数，每个数都有31位，即最大31个结点
int a[N];
int son[M][2],idx;//每个节点非0即1.
int n;

void insert(int x){
    int p =0;
    for(int i=30;i>=0;i--){
        int u = (x>>i) &1;//取出x的第i位是什么
//        没有儿子的话，创建出来。 然后p走到儿子上（这句都得执行，所以不用加else）
        if(!son[p][u]) son[p][u] = ++idx;
        p =son[p][u];
    }
}

int query(int x){
    int p=0;
    int ans =-N;
    for(int i=30;i>=0;i--){
        
//        尽量找和当前位不同的数的位（若0就找1，若1就找0），然后走到这个位上。如果没有只能走相同的数的节点上。
        if(son[p][!u])
        {
            p =son[p][!u];
            ans = ans*2+!u;
        }
        else
        {
            p = son[p][u];
            ans =ans*2 +u;
        }
        
    }
    return ans;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int res =0;
    for(int i=0;i<n;i++){
        insert(a[i]); //插入当前的数。
        int t = query(a[i]);
        
        res = max(res,t^a[i]); //异或的最大的结果。
    }
    
    cout<<res<<endl;
    return 0;
}


