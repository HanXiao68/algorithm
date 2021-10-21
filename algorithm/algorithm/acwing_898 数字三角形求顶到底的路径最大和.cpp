//
//  acwing_898 数字三角形求顶到底的路径最大和.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/21.
//

#include<iostream>
#include<algorithm>
#include <cstring>

// 如果涉及到i-1这样的下标，就使用从1开始循环（会少一些判断，方便）。
// DP的时间复杂度：状态的数量 * 转移的时间复杂度。

using namespace std;
const int N = 510;
const int INF= 1e9;

int a[N][N];
int f[N][N]; //有负数，初始化每个元素为负无穷。
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>a[i][j];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            f[i][j] = -INF; //初始化要从0开始初始化。
        }
    }
    // memset(f,-INF,sizeof f);
    f[1][1] = a[1][1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            f[i][j] = max(f[i-1][j],f[i-1][j-1])+a[i][j];
        }
    }
    int res =-INF;
    for(int i=1;i<=n;i++)
        res = max(res,f[n][i]);

    cout<<res;


    return 0;
}

