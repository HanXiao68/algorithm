////
////  acwing_799 最长连续不重复子序列的长度.cpp
////  algorithm
////
////  Created by 韩霄 on 2021/10/8.
////双指针。使用s【a[i]】 来判断出现的个数。
////双指针的形式for +while
//
//#include <stdio.h>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//const int N = 1e5+10;
//int a[N],s[N];
//int main(){
//    int n;
//    int res =0;
//    cin>>n;
//    for(int i=0;i<n;i++) cin>>a[i];
//    
//    for(int i=0,j=0;i<n;i++){
//        s[a[i]] ++;
//        while(s[a[i]] > 1){
//            s[a[j]]--;
//            j++; 
//        }
//        res = max(res,i-j+1);
//    }
//    cout<<res<<endl;
//    
//    return 0;
//}
