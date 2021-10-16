//
//  acwing_2816 判断子序列.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/8.
// 判断a是否是b的子序列。
//两种写法：1.按照常规思路写。 2.套用模板写。
//
//#include <stdio.h>
//#include <iostream>
//
//using namespace std;
//
//const int N = 1e5+10;
//int a[N],b[N];
//int n,m;
//
//int main(){
//    cin>>n>>m;
//    for(int i=0;i<n;i++) cin>>a[i];
//    for(int i=0;i<m;i++) cin>>b[i];
//
//    int i=0,j=0;
//    while(i<n && j<m){
//        if(a[i] ==b[j]) i++;
//        j++;//这句不管if执行不执行。都会执行
//    }
//    if(i == n) puts("Yes");
//    else puts("No");
//    return 0;
//}

////模板写
//#include<iostream>
//
//using namespace std;
//const int N=1e5+10;
//int a[N],b[N];
//int n,m;
//int main(){
//    cin>>n>>m;
//    for(int i=0;i<n;i++) cin>>a[i];
//    for(int i=0;i<m;i++) cin>>b[i];
//    for(int i=0,j=0;i<n;i++){
//
//        while(j<m&&a[i] !=b[j]){
//            j++;
//        }
//        if(j == m)
//        {
//            puts("No");
//            return 0;
//        }
//        j++;
//    }
//    puts("Yes");
//    return 0;
//}
