//
//  leetcode_437 路径总和3.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
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
    int ans = 0;

    void dfs(TreeNode* root,int sum){

        if(!root) return; //返回条件是：所有条件全都遍历完了
        sum -= root->val;
        if(sum == 0) ans++; //结果自增，但是不返回
        dfs(root->left,sum);

        dfs(root->right,sum);
    }
    int pathSum(TreeNode* root,int sum){

        if(!root) return ans;

        dfs(root,sum);
        pathSum(root->left,sum);

        pathSum(root->right,sum);

        return ans;
    }
};
