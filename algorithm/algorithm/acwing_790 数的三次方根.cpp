////
////  acwing_790 数的三次方根.cpp
////  algorithm
////
////  Created by 韩霄 on 2021/10/5.
////用二分来实现夹逼定理，为了精度！
//
//#include <stdio.h>
//#include <iostream>
//
//using namespace std;
//
//int main(){
//
//    double n;
//    scanf("%lf",&n);
//    double l = -1e5,r = 1e5;
//    double mid ;
//    while (r - l > 1e-8){
//        mid =(l+r) / 2;
//        if(mid *mid *mid > n){
//            r =mid;
//        }
//        else l = mid;
//    }
//    printf("%lf",mid);
//    return 0;
//}
//
//
