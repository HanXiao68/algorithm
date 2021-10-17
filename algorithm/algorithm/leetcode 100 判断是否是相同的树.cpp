//
//  leetcode 100 判断是否是相同的树.cpp
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
//        这里只用管当前层。下一层递归的时候会判断。不用在当前层判断。
            if(!p &&!q) return true;
            if((p&&!q) || (!p&&q)) return false;
            if(p->val !=q->val) return false;
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
