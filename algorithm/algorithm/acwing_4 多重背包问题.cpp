//
//  acwing_4 多重背包问题.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/21.
//

#include <iostream>

using namespace std;

const int N = 110;
int v[N],w[N],s[N];
int f[N][N];
int n,m;

// 暴力解法
int main(){

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i]>>s[i];

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=s[i] &&k*v[i] <=j;k++)
            {
                // 理解状态转移最重要！！！
                f[i][j] = max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
            }
        }
    }
    cout<<f[n][m];
    return 0;
}

作者：HX_6
链接：https://www.acwing.com/activity/content/code/content/1798350/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
