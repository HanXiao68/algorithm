//
//  leetcode_10 正则表达式匹配.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.empty() || p.empty() ) {
                return false;
            }
            //二维数组 表示s的前i个字符能否被p的前j个字符匹配
            vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
            //bool[][] dp = new boolean[s.length()+1][p.length()+1];
            dp[0][0] = true;
            
            //外层循环遍历p中的字符
            for(int i=0;i<p.length();i++) {
                //*课代表匹配零个或多个前面的那一个元素
                if(p[i] == '*' && dp[0][i-1]) {
                    dp[0][i+1] = true;
                }
            }
            
            for(int i=0;i<s.length();i++) {
                for(int j =0; j<p.length();j++) {
                    //如果是任意元素   或者s和p的对应字符匹配
                    if(p[j] == '.' || p[j]==s[i]) {
                        dp[i+1][j+1] = dp[i][j];
                    }
                    if(p[j] =='*') {
                        //如果p的第j个字符是*的情况下，第j-1个字符不和i匹配，并且j-1 的字符不是 .
                        if(p[j-1] !=s[i] &&p[j-1]!='.') {
                            dp[i+1][j+1] = dp[i+1][j-1];
                        }else {
                            //如果p的第j个字符是*的情况下，第j-1个字符和i匹配，或者j-1 的字符是 .
                            dp[i+1][j+1] = dp[i+1][j-1] ||dp[i][j+1] ||dp[i+1][j-1];
                        }
                    }
                }
            }
            
            return dp[s.size()][p.size()];
    }
    
};
