//
//  acwing_795 前缀和.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/7.
//

#include <iostream>

using namespace std;
int n,m;
const int N = 1e5+10;
int a[N],sum[N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i] = sum[i-1]+a[i];
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        cout<<(sum[r]-sum[l-1])<<endl;
      
    }
    
    return 0;
}
