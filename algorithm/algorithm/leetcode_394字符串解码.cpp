//
//  leetcode_394字符串解码.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
    stack<string> resStack;
    int num = 0;
    string res;
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            res.push_back(s[i]);
        } else if (isdigit(s[i])) {
            num = num * 10 + s[i] - '0';
        } else if (s[i] == '[') {//左括号往数栈和res栈里push（）
            resStack.push(res);
            res = "";
            numStack.push(num);
            num = 0;
        } else { //右括号 碰到右括号就开始弹栈计算。
            for (int j = 0; j < numStack.top(); j++) {
                resStack.top() += res;
            }
            numStack.pop();
            res = resStack.top();
            resStack.pop();
        }
    }
    return res;
    }
};
