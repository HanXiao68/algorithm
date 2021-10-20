//
//  acwing_3 完全背包问题.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/20.
//

#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1010;
int v[N],w[N];
int f[N];
int n,m;

// 最原始的做法
// int main(){
//     cin>>n>>m;
//     for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=0;j<=m;j++)
//         {
//             for(int k=0;k*v[i] <= j;k++)
//             {
//                 // 将当前状态和 转移过来的状态的大者作为f[i][j]的结果
//                 f[i][j] = max(f[i][j],f[i-1][j-k*v[i]]+k * w[i]);
//             }
//         }
//     }
    
//     cout<<f[n][m]<<endl;
//     return 0;
// }
// ==================================================
// 可以优化成二维的
// int main(){
//     cin>>n>>m;
//     for(int i = 1;i <= n;i++) cin>>v[i]>>w[i];
    
//     for(int i = 1;i <= n;i++)
//     {
//         for(int j = 0;j <= m;j++)
//         {
//             f[i][j] = f[i-1][j];
//             if(j >= v[i]) f[i][j] = max(f[i][j],f[i][j-v[i]]+w[i]);
//         }
//     }
    
//     cout<<f[n][m]<<endl;
//     return 0;
// }

// 可以优化成一维的
int main(){
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>v[i]>>w[i];
    
    for(int i = 1;i <= n;i++)
    {
        for(int j = v[i];j <= m;j++)
        {
            
            if(j >= v[i]) f[j] = max(f[j],f[j-v[i]]+w[i]);
        }
    }
    
    cout<<f[m]<<endl;
    return 0;
}




