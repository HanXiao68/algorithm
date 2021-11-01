////
////  acwing_39 数组中和等于target的组合.cpp
////  algorithm
////
////  Created by 韩霄 on 2021/10/23.
////
//
class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        
        dfs(a,target,0);
        return res;
    }
    // 完全背包问题
    void dfs(vector<int>& a, int target,int idx){
       if(target ==0) {res.push_back(temp);return;}
       if(idx==a.size()) return;
       for(int i=0;a[idx]*i<=target;i++){
           dfs(a,target-a[idx]*i,idx+1);
           temp.push_back(a[idx]);
       }
       for(int i=0;a[idx]*i<=target;i++){
           temp.pop_back();
           
       }
    }
};
