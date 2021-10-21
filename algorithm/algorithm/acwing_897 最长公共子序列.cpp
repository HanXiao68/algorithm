//
//  acwing_897 最长公共子序列.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/21.
//

#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1010;
char a[N],b[N];
int f[N][N];
int main(){
    int n,m;
    cin>>n>>m;
    cin>>a+1>>b+1;
   // cout<<a+1<<" "<<b+1<<endl;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j] = max(f[i-1][j],f[i][j-1]);
            if(a[i] ==b[j]) f[i][j] = f[i-1][j-1]+1;
        }
    }
    cout<<f[n][m];
    return 0;
}



