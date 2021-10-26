//
//  leetcode_17 电话号码的字母组合.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    map<char,string> M ={
        {'2',"abc"},{'3',"def"},{'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };

    vector<string> res;
    string current;
    void dfs(int index,string digits){
        if(index == digits.size()) res.push_back(current);

        for(int i =0;i< M[digits[index]].size();i++){//遍历字符对应的值
            current.push_back(M[digits[index]][i]);
            dfs(index+1,digits);
            current.pop_back();
            
        }


    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.size() ==0) return res;

        dfs(0,digits);
        return res;
    }
};
