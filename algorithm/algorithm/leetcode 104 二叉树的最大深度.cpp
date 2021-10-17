//
//  leetcode 104 二叉树的最大深度.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/17.
//层序遍历求解

#include <queue>

using namespace std;

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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int num =0;
        queue<TreeNode* > q;
        vector<TreeNode*> res;
        q.push(root);
        while(q.size()){
            int sz = q.size();
            num++;
            for(int i=0;i<sz;i++){
                TreeNode *temp = q.front();q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return num;
    }
};
