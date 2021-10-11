////
////  acwing_801 二进制中1的个数.cpp
////  algorithm
////
////  Created by 韩霄 on 2021/10/9.
////
//
//#include <stdio.h>
//#include <iostream>
//
//using namespace std;
//const int N =1e5+10;
//int a[N];
//int n;
////返回最低位的1，后面加上后面位数的0.
//int lowbit(int& x){
//    return -x &x;
//}
//int main(){
//    cin>>n;
//    
//    for(int i=0;i<n;i++)
//    {
//        int res =0;
//        cin>>a[i];
//        while(a[i]) a[i] -=lowbit(a[i]),res++;
//        cout<<res<<" ";
//    }
//    
//    
//    return 0;
//}
//
//
//
//
