//
//  leetcode_102 二叉树的层序遍历.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/17.
//

#include <vector>
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
    vector<vector<int>> res;
      
       vector<vector<int>> levelOrder(TreeNode* root) {
           if(!root) return res;
           queue<TreeNode* > q;
           q.push(root);
           while(q.size()){
               // 每一层都要new一个res_row.或者放成全局变量，每次清空也行
                   vector<int> res_row;
                   int sz = q.size();
                   for(int i=0;i<sz;i++)
                   {
                       TreeNode*  temp = q.front();q.pop();
                       res_row.push_back(temp->val);
                       if(temp->left) q.push(temp->left);
                       if(temp->right) q.push(temp->right);
                   }

               res.push_back(res_row);
           }
           return res;
       }
    
};
