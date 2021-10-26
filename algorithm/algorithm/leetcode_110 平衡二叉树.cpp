//
//  leetcode_110 平衡二叉树.cpp
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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int left = hei(root->left);
        int right = hei(root->right);
        if(abs(left-right)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int hei(TreeNode* root){
        if(!root) return 0;
        int left = hei(root->left);
        int right = hei(root->right);
        int res = max(left,right) + 1;
        return res;
    }
};
