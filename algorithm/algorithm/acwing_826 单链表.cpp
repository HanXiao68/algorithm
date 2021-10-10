//
//  acwing_826 单链表.cpp
//  algorithm
// 数组实现单链表--静态链表。
//  Created by 韩霄 on 2021/10/10.
//
// 用数组实现单链表。是静态链表。用new是动态链表，速度非常慢。
// 设置两个数组，一个存数据。一个存指针，-1表示空指针。

// head表示头结点的下标。
// e[i]表示节点i的值。
// ne[i]表示节点i的next指针是多少。
// idx存储当前已经用到了哪个点
//要想找链表的前面一个点只能从头开始遍历。

// H x，表示向链表头插入一个数 x。
//     操作：
// D k，表示删除第 k 个插入的数后面的数（当 k 为 0 时，表示删除头结点）。
//     操作：删除下标为k-1的数
// I k x，表示在第 k 个插入的数后面插入一个数 x（此操作中 k 均大于 0）
//     操作：在下标为k-1的后面插入一个点。
#include <stdio.h>
#include <iostream>

using namespace std;
const int N = 1e5+10;
int n;
int head,idx,e[N],ne[N];

void init(){
    head = -1;
    idx = 0;
}
void add_head(int x){ //头插法
    e[idx] =x;
    ne[idx] = head;
    head = idx;
    idx++;
}

void add_nor(int p,int x){
    e[idx] = x;
    ne[idx] = ne[p];
    ne[p] = idx;
    idx++;
}

void remove(int k){
    ne[k] = ne[ne[k]];
}
int main(){
    init();
    cin>>n;
    char c;
    while(n--){
        cin>>c;
        if(c =='H'){
            int x;cin>>x;
            add_head(x);
        }else if(c == 'D'){
            int k;cin>>k;
            if(!k) head = ne[head];
            remove(k-1);
        }else if(c == 'I'){
            int p,x;cin>>p>>x;
            add_nor(p-1,x);
        }
    }
    
    for(int i=head;i!=-1;i = ne[i])
        cout<<e[i]<<" ";
    
    return 0;
}






