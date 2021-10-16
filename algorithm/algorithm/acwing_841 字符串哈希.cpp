//
//  acwing_841 字符串哈希.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/16.
//

#include <iostream>
#include<string>

using namespace std;

int n,m;
string str;

int main(){
    cin>>n;cin>>m;
    cin>>str;
    
//    cout<<str.substr(0,3)<<endl;
//    cout<<str.substr(4,3)<<endl;
    while(m--){
        int l1,l2,r1,r2;
        cin>>l1>>r1>>l2>>r2;
        string str1 = str.substr(l1-1,r1-l1+1);
        string str2 = str.substr(l2-1,r2-l2+1);
        cout<<str1<<endl;
        cout<<str2<<endl;
        if(str1 == str2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
    return 0;
}


