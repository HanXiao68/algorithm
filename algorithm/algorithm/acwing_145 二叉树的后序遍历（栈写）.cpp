//
//  acwing_145 二叉树的后序遍历（栈写）.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/23.
//

#include <stdio.h>
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode* > st;

        while(root || st.size()){
            while(root){
                res.push_back(root->val);
                st.push(root);
                root = root->right;
            }
            root = st.top()->left;
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
