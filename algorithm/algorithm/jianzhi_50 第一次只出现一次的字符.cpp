//
//  jianzhi_50 第一次只出现一次的字符.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char,int> um;
        for(int i=0;i<str.size();i++){
            um[str[i]]++;
            
        }
        for(int i =0;i<str.size();i++)
        {
            if(um[str[i]] == 1) return i;
        }
        return -1;
    }
};
