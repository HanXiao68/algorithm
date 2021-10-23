//
//  leetcode_20 有效的括号.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/23.
//

class Solution {
public:
    bool isValid(string s) {
        if(s.size() %2 ==1) return false;
        stack<char> st;
        unordered_map<char,char> mp ={
            {')','('},
            {']','['},
            {'}','{'}
        };
        for(auto x : s){
            if(mp.count(x)){
                if( st.size()==0 || mp[x] !=st.top()) return false;
                st.pop();
            }
            else{
                st.push(x);
            }
        }
        return st.empty();
    }
};
