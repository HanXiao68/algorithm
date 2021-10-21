//
//  acwing_902 最短编辑距离.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/22.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1010;
int f[N][N];
char a[N],b[N];
int main(){
    int n;cin>>n;
    cin>>(a+1);
    int m;cin>>m;
    cin>>(b+1);
    
    for(int i=0;i<=n;i++){f[i][0] = i;}
    for(int j=0;j<=m;j++) f[0][j] = j;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
//            先赋值横竖。只会大不会小，因为最终是要最小的所以不影响。如果大了，后面还会mimin取出当前的最优结果。
            f[i][j] = min(f[i-1][j],f[i][j-1])+1;
//            再比较对角线。得到当前的最小的。
            if(a[i] ==b[j]) f[i][j] = min(f[i][j],f[i-1][j-1]);
            else f[i][j] = min(f[i][j],f[i-1][j-1]+1);
        }
    }
    cout<<f[n][m];
    return 0;
}
