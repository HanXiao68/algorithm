//class Solution {
//public:
//
//  test_hello.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//
//
//#include <stdio.h>
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//   vector<string> res;
//   vector<string> restoreIpAddresses(string s) {
//       if(s.size() ==0) return res;
//       helper(s,"",4);
//       return res;
//   }
//       void helper(string s,string out,int k){
//           if(k ==0){
//               if(s.empty()) res.push_back(out);
//           }
//           else{
//               for(int i=1;i<=3;i++){
//                   if(i<=s.size() &&isvalid(s.substr(0,i))){
//                       if(k ==1)
//                       helper(s.substr(i),out+s.substr(0,i),k-1);
//                       else{
//                           helper(s.substr(i),out+s.substr(0,i)+'.',k-1);
//                       }
//                   }
//               }
//           }
//       }
//       bool isvalid(string s){
//           if(s.empty() || s.size() >3 ||(s.size()>1&&s[0]=='0')) return false;
//
//              int num =0;
//              for(auto x:s) num = num*10+x-'0';
//
//              return num>=0 &&num<=255;
//       }
//};

//};
