//
//  acwing_895 最长上升子序列.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/21.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int a[N],f[N];
int main(){
    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    
    for(int i=1;i<=n;i++){
        f[i]=1;//以每个数为结尾的最长子序列的初始化为1.
        for(int j=1;j<i;j++){
            if(a[j]<a[i]) f[i] = max(f[i],f[j]+1);
        }
    }
    int res =0;
    for(int i=1;i<=n;i++){
        res = max(res,f[i]);
    }
    cout<<res;
    return 0;
}
