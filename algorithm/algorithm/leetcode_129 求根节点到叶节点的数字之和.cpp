//
//  leetcode_129 求根节点到叶节点的数字之和.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/20.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res =0;
    void dfs(TreeNode* u, int ans){
        
        if(!u) return;
        ans = ans*10 +u->val;
        if(u->left) dfs(u->left,ans);
        if(u->right) dfs(u->right,ans);
        if(!u->left && !u->right) res +=ans;
    }
    int sumNumbers(TreeNode* root) {
        
        dfs(root,0);
        return res;
    }
};
