//
//  leetcode_103 二叉树的锯齿形层序遍历.cpp
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(!root) return res;
        bool flag = true;
        queue<TreeNode* > q;
        q.push(root);
        while(q.size()){
            int sz = q.size();
            vector<int> level;
            for(int i =0;i<sz;i++){
                TreeNode* temp = q.front();
                level.push_back(temp->val);q.pop();
                
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                    
            }
            reverse(level.begin(),level.end()); flag = !flag;
            res.push_back(level)
        }
    }
};
