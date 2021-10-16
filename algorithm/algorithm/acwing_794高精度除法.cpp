////
////  高精度除法.cpp
////  algorithm
////
////  Created by 韩霄 on 2021/10/7.
//// 使用与手算相同的思路
//
//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//string a;
//int b,r;
//
//vector<int> div(vector<int>& a,int b,int& r){
//    vector<int> c;//除数也是用的vector存储的。
//    r =0;
//    for(int i=a.size()-1;i>=0;i--)
//    {
//        r = r*10 +a[i];
//        c.push_back(r/b); //这里是b。不是10.和10没有关系
//        r %= b;
//
//    }
//    reverse(c.begin(),c.end());
//    while(c.size() >1 && c.back()== 0) c.pop_back();
//    for(int i=c.size()-1;i>=0;i--)
//        cout<<c[i];
//
//    return c;
//}
//
//int main(){
//    cin>>a>>b;
//    vector<int> A;
//    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
//
//    int r;
//    div(A,b,r);
//
//    cout<<endl;
//    cout<<r<<endl;
//
//
//    return 0;
//}
