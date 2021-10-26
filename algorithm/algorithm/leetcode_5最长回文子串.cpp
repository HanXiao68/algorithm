//
//  leetcode_5最长回文子串.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    string longestPalindrome(string s) {
          string res;
        if(s.size()==0 ||s.size() ==1) return s;
       
        for(int i=0;i<s.size();i++){
            int l =i-1,r = i+1;
            // 偶回文
            while(l>=0 && r<s.size() && s[l]==s[r]) l--,r++; //最后停下来的位置是 不相等的两个地方。即，【l+1，r-1】 是最大回文串
            if(res.size() < r-l-1) res = s.substr(l+1,r-l-1);// substr参数：从哪开始，多少长度
            // 奇回文。 奇回文总比偶回文要长
            l =i,r =i+1;
            while(l>=0 &&r <s.size() && s[l] ==s[r]) l--,r++;
            if(res.size() <r-l-1) res = s.substr(l+1,r-l-1);

        }

        return res;
    }
};
