//
//  leetcode_337 打家劫舍3 树形DP.cpp
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
     unordered_map<TreeNode*,int > vals;

    int rob(TreeNode* root) {
        if(root ==NULL) return 0;
        if(root->left ==NULL && root->right ==NULL) return root->val;

        if(vals[root]) return vals[root];

        // 不偷父节点
        int val = rob(root->left) + rob(root->right);
        
        // 偷父节点
        int val2 = root->val;
        if(root->left) val2 +=rob(root->left->left) + rob(root->left->right);
        if(root->right) val2 +=rob(root->right->left) + rob(root->right->right);
        vals[root] =  max(val,val2);
        return  vals[root];
    }
};
