//
//  acwing_839 使用数组模拟堆.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/16.
//

#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

const int N =1e5+10;
//ap[]表示交换后的数组。pa【】表示交换后的下标。（因为要记录第k次插入的数，所以要专门搞一个数组记录第几次插入的）。
int a[N],ap[N],pa[N];
int sz;
 
void heap_swap(int x,int y){
    swap(pa[ap[x]],pa[ap[y]]);
    swap(ap[x],ap[y]);
    swap(a[x],a[y]);
}

void down(int u){
    
    int t = u;
    if(u*2 <=sz && a[u*2]<a[t]) t = u*2;
    if(u*2+1<=sz &&a[u*2+1]<a[t]) t = u*2+1;
    if(u != t){
        heap_swap(u,t);//交换数，不是交换下标！！！！
        down(t);
    }
}

void up(int u){
    while(u/2 >0 &&a[u/2]>a[u]){
        heap_swap(u/2,u);
        u /=2;//从u的位置转移到他的父节点，一直往上欧，直到根节点。
    }
}
int main(){
    int n;cin>>n;
    string op;
    int m= 0;
    while(n--){
        cin>>op;
        if(op =="I"){
            int x;cin>>x;
            m++;
            pa[m] = sz;ap[sz] = m;
            a[++sz] = x;
            
            up(sz);
        }else if(op =="PM"){
            cout<<a[1]<<endl;
        }else if(op =="DM"){
            heap_swap(1, sz);
            sz--;
            down(1);
        }else if(op =="D"){
            int k;
            cin>>k;
            k = pa[k];
            heap_swap(k, sz);
            sz--;
//            down();up()就能保证中间的数删除后，顺序给排好。
            down(k);up(k);
        }else if(op =="C"){
            int k,x; cin>>k>>x;
            k = pa[k];
            a[k] = x;
            down(k);up(k);
        }
    }
    
    
    
    return 0;
}




