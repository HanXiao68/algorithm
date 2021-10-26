//
//  leetcode_39 组合总和.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    vector<vector<int>> res;
    vector<int> ans;
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        sort(a.begin(),a.end());
        dfs(a,target,0);
        return res;
    }

    void dfs(vector<int>& a, int target,int idx){
        
        if(target ==0) {
            res.push_back(ans);
            return;
        }
        if(idx == a.size()) return;

        if(a[idx] <= target){
            dfs(a,target,idx+1);
            ans.push_back(a[idx]);
            dfs(a,target-a[idx],idx);
            ans.pop_back();
        }

    }
};
