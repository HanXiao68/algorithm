//
//  acwing_828模拟栈（使用数组）.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/11.
//

#include <stdio.h>
#include <iostream>

using namespace std;

const int N  = 1e5+10;
int a[N];
int n;
int tt;
int pp;
int main(){
    cin>>n;
    string str;
    while(n--){
        cin>>str;
        if(str == "push"){
            int x;cin>>x;
            a[++tt] = x;
        }else if(str =="query"){
            cout<<a[tt]<<endl;
        }else if(str =="pop"){
            tt--;
        }else if(str =="empty"){
            if(tt == 0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    
    
    return 0;
}

