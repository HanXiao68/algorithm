//
//  acwing_788逆序对的数量.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/5.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int n;
const int N = 1e5+10;
int a[N],temp[N];
typedef long long LL;
LL merge_count(int a[],int l,int r){
    if(!(l<r)) return 0;
    LL mid = (l+r)>>1;
    LL res = merge_count(a,l,mid) + merge_count(a,mid+1,r);
    int i = l,j = mid+1,k = 0;

    while(i<=mid && j<=r){
        if(a[i]<a[j]) temp[k++] = a[i++];
        else
        {
            temp[k++] = a[j++];
            //关键句-【i，mid】都与j形成逆序对。【和归并排序不一样的地方】
            res +=mid -i+1;
        }
        
    }
    while(i<=mid) temp[k++] = a[i++];
    while(j<=r) temp[k++]  =a[j++];

    for(int m=l,k=0;m<=r;m++) a[m] = temp[k++];
    return res;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    cout<<merge_count(a,0,n-1)<<endl;

    return 0;
}



