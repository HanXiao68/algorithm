//
//  leetcode_139 单词拆分.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet = unordered_set<string>();

        for(auto word :wordDict){
            wordDictSet.insert(word);
        }

        vector<bool> dp = vector<bool>(s.size()+1);


        dp[0] = true;

        for(int i =1;i<= s.size();i++){
            for(int j=0;j<i;j++){
                // dp[j] 和（j,i）的部分都在。则dp[i] 就更新为TRUE；
                if(dp[j] && wordDictSet.find(s.substr(j,i-j)) !=wordDictSet.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
        }
};
