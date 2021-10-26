//
//  leetcode_3 无重复字符的最长子串.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          unordered_set<char> um;
        int n = s.size();

        int j = -1,ans = 0;
        for(int i=0;i<n;i++){
            // 下标是i-1。所以从1开始。
            if(i != 0) um.erase(s[i-1]);
            // 对于每个i的位置，j都往后看。最大不重复的
            while(j +1<n &&um.count(s[j+1]) == 0){
                um.insert(s[j+1]);
                j++;
            }
            // 每次i都要比较取最大。
            ans = max(ans,j-i+1);
        }

        return ans ;
    }
};
