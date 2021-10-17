//
//  leetcode 101 判断是否是对称的二叉树.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/17.
//

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    bool isSym(TreeNode* left,TreeNode* right){
        if(!left && !right) return true;
        if((!left &&right) ||(left &&!right)) return false;
        if(left->val != right ->val) return false;
        
        return isSym(left->left, right->right) && isSym(left->right, right->left);
                                                
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSym(root->left,root->right);
    }
};
