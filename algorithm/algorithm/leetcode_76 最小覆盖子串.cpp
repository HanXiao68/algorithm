//
//  leetcode_76 最小覆盖子串.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> um,window;//统计个数的
        for(char c:t) um[c]++;

        int left =0,right =0;
        int valid = 0;

        int start =0,len = INT_MAX;
        while(right < s.size()){
            char c = s[right];
            right++;
            // need中有这个数的话
            if(um.count(c)){
                window[c]++;
                if(window[c] == um[c]) valid++;
            }
            while(valid == um.size()){
                if(right - left <len){
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                left++;
                if(um.count(d)){
                    if(window[d] ==um[d]) valid--;
                    window[d] --;
                }
            }
        }
        return len == INT_MAX ? "":s.substr(start,len);
    }
};
