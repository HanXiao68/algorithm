//
//  acwing_3302.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/11.
//核心：1.两个栈：一个放数，一个放操作。  2.操作的栈中优先级：左括号无优先级直接往里搁，右括号优先级最高，往出弹。
//    +- 优先级小于 */


#include <stdio.h>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;
stack<int> n;
stack<char> op;

//优先级表
unordered_map<char, int> h{
    {'+',1},{'-',1},{'*',2},{'/',2}
};
void  eval(){
    int a = n.top();
    n.pop();
    int b = n.top();
    n.pop();
    char p = op.top();
    op.pop();
    
    int r= 0;
    if(p =='+') r = b+a;
    if(p =='-') r = b-a;
    if(p =='*') r = b*a;
    if(p =='/') r = b/a;
    n.push(r);
}
int main(){
    
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(isdigit(str[i]))
        {
            int x =0,j = i;
            while(j<str.size() && isdigit(str[j])){
                x = x*10+str[j]-'0';
                j++;
            }
            n.push(x);
            i = j-1;
        }
//        左括号直接进
        else if(str[i] == '(') op.push(str[i]);
//        右括号得等到左括号。一块做了运算。
        else if(str[i] == ')'){
            while(op.top() != '(') eval();
            op.pop();//左括号出站。
        }
//       比较优先级
        else{
            while(op.size() && h[op.top()] >=h[str[i]]) eval();
            op.push(str[i]);
        }
        
    }
    while(op.size()) eval();//剩余的操作符计算完。
    cout<<n.top()<<endl;
    return 0;
}

