//
//  acwing_9 分组背包问题.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/21.
//

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 110;
int v[N][N],w[N][N],s[N];
int f[N];//N代表的是V体积
int n,m;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        // 体积要从0开始。
        for(int j=0;j<s[i];j++) cin>>v[i][j]>>w[i][j];
    }

    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            for(int k=0;k<s[i];k++){
                if(v[i][k]<=j)
                    f[j] = max(f[j],f[j-v[i][k]]+w[i][k]);
            }
        }
    }
    cout<<f[m];
    return 0;
}

作者：HX_6
链接：https://www.acwing.com/activity/content/code/content/1798466/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
