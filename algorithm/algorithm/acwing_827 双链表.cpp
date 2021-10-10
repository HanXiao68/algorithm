
//  Created by 韩霄 on 2021/10/10.
//与单链表的区别是：端点插入是包括了左插和右插，而单链表的端点只有头插。删除需要操作左右两侧的指针。
//普通插入：也包括左插和右插。只实现右插。左插的实验为 被插节点的上一个节点的右插。

//注意插入的方式是有个讲究的。右插：RLLR。 左插是LRRL。乱了结果就错了。
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int n;
const int N =1e5+10;

int e[N],L[N],R[N],idx;

void init(){
    R[0] = 1;
    L[1] = 0;
    idx =  2;
}

void insertR(int x){
    R[idx] = 1;
    L[idx] = L[1];
    L[1] = idx;
    R[L[idx]] = idx;
    e[idx] = x;
    idx++;
}
void insertL(int x){
    L[idx] = 0;
    R[idx] = R[0];
    R[0] = idx;
    L[R[idx]] = idx;
    e[idx] = x;
    idx++;
}

void insertK(int k,int x){
    R[idx] = R[k];
    L[idx]  = k;
    L[R[k]] = idx;
    R[k] = idx;
    e[idx] = x;
    idx++;
}
void remove(int k){
    R[L[k]] = R[k];
    L[R[k]] = L[k];
}
int main(){
    cin>>n;
    string c;
    init();
    int k;//k代表位置。
    while(n--){
        cin>>c;
        if(c =="R"){
            int x;cin>>x;
            insertR(x);
        }else if(c =="L"){
            int x;cin>>x;
            insertL(x);
        }else if(c =="IL"){
            int x;cin>>k>>x;
            insertK(L[k+1],x);
        }else if(c =="IR"){
            int x;cin>>k>>x;
            insertK(k+1,x);
        }else if(c =="D"){
            cin>>k;
            remove(k+1);
        }
    }
    for(int i=R[0];i!=1;i = R[i]) cout<<e[i]<<" ";
    
    return 0;
}


