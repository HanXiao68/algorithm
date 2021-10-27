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
//        um代表模式串中的个数统计
        for(char c:t) um[c]++;
//        双指针遍历窗口。相同方向。
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
//            当窗口的内的字母包含了模式串的字母时。
            while(valid == um.size()){
//                若有更小的len 更新len,start.
                if(right - left <len){
                    start = left;
                    len = right - left;
                }
                char d = s[left];
//                左指针往右移。
                   left++;
//                更新左移后的两个窗口大小以及匹配的大小。
                if(um.count(d)){
                    if(window[d] ==um[d]) valid--;
                    window[d] --;
                }
            }
        }
        return len == INT_MAX ? "":s.substr(start,len);
    }
};
