//
//  leetcode_543 二叉树的直径.cpp
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
     int ans =1;
    int diameterOfBinaryTree(TreeNode* root) {
       
        dfs(root);
       return ans-1;

    }
    int dfs(TreeNode* root){
        if(!root) return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);
        ans = max(ans,l+r+1);
        return max(l,r)+1;
    }
};
