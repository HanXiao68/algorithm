//
//  200 186 反转字符串里的单词.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/23.
//双指针 + reverse（迭代器）

class Solution {
public:
    void reverseWords(vector<char>& s) {
        s.push_back(' ');
        int left = 0, right = 0;
        while(right < s.size()){
            if(s[right] == ' '){
                reverse(s.begin() + left, s.begin() + right);
                left = right + 1;
            }
            ++right;
        }
        s.pop_back();
        reverse(begin(s), end(s));
    }
};
