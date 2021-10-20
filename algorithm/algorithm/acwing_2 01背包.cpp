//
//  acwing_2 01背包.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/20.
//

#include<iostream>

using namespace std;

const int N = 1010;
int n,m;
int v[N],w[N];
int f[N][N];
// dp状态的定义是：f[i][j]表示只看前i个物品，总体积是j的情况下。总价值最大是多少
// 不选第i个物品：f[i][j] = f[i-1][j] ; 选第i个物品：f[i][j] = f[i-1][j-vi]
// f[i][j] = max(选第i个情况，不选第i个物品的情况)
// 初始化：f[0][0] = 0


int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];

    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            // 先将当前的f[i][j]初始化为上一次的f[i-1][j]
            f[i][j] = f[i-1][j];
            // 只有当空间j够装时，才会有考虑两种情况。
            if(j >=v[i]) //不用关心这里的j是怎么更新的，背住。后面慢慢理解
                f[i][j] = max(f[i][j],f[i-1][j-v[i]]+w[i]);
        }
    }
        int res = 0;
        for(int i=1;i<=m;i++) res = max(res,f[n][i]);
        cout<<res<<endl;
        return 0;
}


=================================
优化版
// 经典背包问题
// 有N件物品和容量是V的背包。接下来输入每一件物品体积vi和价值wi

#include<iostream>

using namespace std;

const int N = 1010;
int n,m;
int v[N],w[N];
int f[N];//优化方法：用一维的数组


int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];

    for(int i=1;i<=n;i++)
        for(int j=m;j>=v[i];j--)
            f[j] = max(f[j],f[j-v[i]]+w[i]);


        // 最后的f[m]状态量就是答案，这和初始化有关。表示体积小于m的情况下
        // 最大价值是多少
        cout<<f[m]<<endl;
        return 0;
}
