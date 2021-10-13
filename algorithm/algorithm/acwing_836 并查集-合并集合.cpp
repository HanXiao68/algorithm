//
//  acwing_836 并查集-合并集合.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/13.
//重点是这个find函数怎么写！！ p[a] = find(p[a]);!!

#include <stdio.h>
#include <iostream>

using namespace std;
const int N =1e5+10;
int p[N]; //父节点的数组

int find(int a){
//    如果父节点不指向自己，那么久一直往上找父节点
    if(p[a] !=a) p[a] = find(p[a]);
    return p[a];
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i] =i;
    char op;
    while(m--){
        cin>>op;
        if(op =='M')
        {
//            cout<<op<<endl;
            int a,b;
            cin>>a>>b;
//            cout<<a<<" "<<b<<endl;
//            把a的根节点插入到b的根节点下面。完成合并。
            p[find(a)] = find(b);
            
        }else if(op == 'Q'){
//            cout<<op<<endl;
            int a,b;
            cin>>a>>b;
//            cout<<a<<" "<<b<<endl;
//            cin>>a>>b;
            if(find(a) ==find(b)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    
    
    return 0;
}

