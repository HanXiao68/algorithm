//
//  leetcode_124 二叉树的最大路径和.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/26.
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
    int val = INT_MIN;

    int max_path_sum(TreeNode* root,int& val){
        if(root ==nullptr ) return 0;
        int left = max_path_sum(root->left,val);
        int right = max_path_sum(root->right,val);
        int throu = root->val + max(0,left)+max(0,right);
        int ret = root->val + max(0,max(left,right));
        // 更新val
        val = max(val,max(throu,ret));
        return ret;
    }
    int maxPathSum(TreeNode* root) {
         max_path_sum(root,val);
         return val;
    }
};
