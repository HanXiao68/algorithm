////
////  acwing_792 高精度减法.cpp
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
//string a,b;
//
//bool cmp(vector<int>& a,vector<int>&b){
//    if(a.size() != b.size()) return a.size() <b.size();
//    else if(a.size() == b.size()){
//        for(int i=a.size()-1;i>=0;i--)
//        {
//            if(a[i] != b[i]) return a[i]<b[i];
//        }
//
//    }
//    return false;
//}
////减法涉及到比大小。不只是长度，还要比每个字母。
//void sub(vector<int>&a,vector<int>& b){
//    if(cmp(a,b))
//    {
//        cout<<'-';
//        return sub(b,a);
//    }
//    int t =0;
//    vector<int > c;
//    for(int i=0;i<a.size();i++)
//    {
//        t = a[i] -t;
//        if(i <b.size()) t -=b[i];
//
//        c.push_back((t+10)%10);
//
//        if(t < 0) t = 1;
//        else t = 0;
//    }
////    去除前导0.
//    while(c.size()>1 && c.back() ==0) c.pop_back();
//    for(int i=c.size()-1;i>=0;i--) printf("%d",c[i]);
//}
//
//int main(){
//    cin >>a>>b;
//
//    vector<int> A;
//    vector<int> B;
//
//    for(int i=a.size()-1;i >=0 ;i--) A.push_back(a[i]-'0');
//    for(int i=b.size()-1;i >=0;i--) B.push_back(b[i]-'0');
//
//    sub(A,B);
//
//
//
//    return 0;
//}
//
