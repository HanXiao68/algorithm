////
////  acwing_791 高精度加法.cpp
////  algorithm
////
////  Created by 韩霄 on 2021/10/7.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//string a,b;
//
//void add(vector<int>& a,vector<int>& b){
//    vector<int> c;
//    int sz = max(a.size(),b.size());
//    int t = 0;
//    for(int i=0;i<sz;i++){
//        if(i< a.size()) t +=a[i];
//        if(i<b.size()) t +=b[i];
//        c.push_back(t%10);
//        t /= 10;
//    }
//    if(t) c.push_back(1);
//    for(int i=c.size()-1;i>=0;i--) printf("%d",c[i]);
//}
//int main(){
//    cin>>a>>b;
//
//    vector<int> A;
//    vector<int> B;
//    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
//    for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');
//    add(A,B);
//    return 0;
//}
