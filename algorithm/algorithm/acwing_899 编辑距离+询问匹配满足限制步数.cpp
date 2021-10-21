//
//  acwing_899 编辑距离+询问匹配满足限制步数.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/22.
//

#include <stdio.h>
// 这道题是编辑距离的复杂版，需要处理输入输出。以及数组。好题！！
// 这道题问的是。前n个字符串中有几个字符串满足询问？？输出满足的字符串的个数！！
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int N = 1010;
int n,m;
char str[15][N];
int f[N][N];
int edit_distance(char a[],char b[]){
    int l1 = strlen(a+1);
    int l2 = strlen(b+1);
    for(int i=0;i<=l1;i++) f[i][0] = i;
    for(int i=0;i<=l2;i++) f[0][i] = i;
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            f[i][j] = min(f[i-1][j],f[i][j-1])+1;
            f[i][j] = min(f[i][j],f[i-1][j-1]+(a[i] != b[j]));
        }
    }
        return f[l1][l2];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str[i] + 1);
       // cout<<str[i]+1<<endl;
    }
    
    for(int i=1;i<=m;i++)
    {
        char s[15];
        int limit;
        scanf("%s%d",s+1,&limit);
        int res =0;
        for(int i=1;i<=n;i++)
            if(edit_distance(str[i],s) <= limit) res++;
        cout<<res<<endl;
    }
    
    return 0;
}

