//
//  leetcode_222 完全二叉树的节点个数.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/21.
//

//时间复杂度是loglogn 。比普通遍历时间要小。
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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int x =1,y=1;//表示左右子树+根节点的高度。
        auto l = root->left,r =root->right;
        while(l) {l=l->left;x++;}
        while(r) {r = r->right;y++;}
        if(x == y) return (1<<x)-1;//2^n+1
        return countNodes(root->left)+1 +countNodes(root->right);
    }
};
