//
//  leetcode_49 字母异味词分组.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        map<string,vector<string> > mp;

        for(int i =0;i< strs.size();i++){
            string str = strs[i];
            sort(str.begin(),str.end());

            if(mp.find(str) == mp.end())
            {
                vector<string> item;
                mp[str] = item;
            }


            mp[str].push_back(strs[i]);
        }

        for(auto x : mp){
            res.push_back(x.second);
        }

        return res;
    }
};
