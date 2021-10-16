////
////  高精度乘法.cpp
////  algorithm
////
////  Created by 韩霄 on 2021/10/7.
////注意：乘法和加减不一样。输入是一个string一个int。
//
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//string a;
//int b;
//
//void multi(vector<int>& a,int b){
//
//    vector<int> c;
//
//    int t =0;
//    for(int i=0;i<a.size();i++)
//    {
//        t +=a[i]*b;
//       // cout<< t<<" "<<t%10<<endl;
//        c.push_back(t %10);
//        t /= 10;
//    }
//    if(t) c.push_back(t);
//
//    while(c.size() >1 &&c.back() ==0) c.pop_back();
//    for(int i=c.size()-1;i>=0;i--) cout<<c[i];
//    
//
//}
//int main(){
//    cin>>a>>b;
//    vector<int >A;
//    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
//
//
//    multi(A,b);
//
//    return 0;
//}
//
//
