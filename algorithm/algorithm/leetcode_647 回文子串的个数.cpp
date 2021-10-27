//
//  leetcode_647 回文子串的个数.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    int countSubstrings(string s) {
     
        if(s.empty()) return 0;

        int size = s.size(),res =0;
        
        for(int i=0;i <size; ++i){
            //对每个位置中心扩散
            helper(s,i,i,res);//他为中心的奇数个扩散
            helper(s,i,i+1,res);//他和他的下一个为中心的偶数个扩散。
        }
        return res;

    }
    void helper(string &s,int i,int j,int&res){
        while(i>=0 && j< s.size() &&s[i] ==s[j]){
            --i,++j;
            ++res;
        }
    }
    
};
