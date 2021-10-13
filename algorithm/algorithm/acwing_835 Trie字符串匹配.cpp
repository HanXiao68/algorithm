//
//  acwing_835 Trie字符串匹配.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/12.
//

#include <stdio.h>
#include <iostream>

using namespace std;
int n;
const int N = 2e4+10;
//初始化的最多的节点就是N*26个。
int son[N][26],cnt[N],idx;
char str[N];
void insert(char str[]){
    int p = 0;
    for(int i=0;str[i];i++){
        int u = str[i] -'a';
        
        if(!son[p][u])  son[p][u] = ++idx; //没有的话激活。这个idx???到底什么作用？
        p = son[p][u]; //有的话p指针往下移动
    }
    
    cnt[p]++;//以p指向的这个字符为结尾的单词数量增加一个。
}

int query(char str[]){
    int p =0;
    for(int i=0;str[i];i++)
    {
        int u = str[i] -'a';
        if(son[p][u]) p = son[p][u];
        else return 0;
    }
    return cnt[p];
    
}

int main(){
    cin>>n;
    char c;
    
    while(n--){
        cin>>c;
        scanf("%s",str+1);
        if(c =='I'){
            insert(str+1);
        }else if(c =='Q'){
            cout<<query(str+1)<<endl;
        }
    }
    return 0;
}


