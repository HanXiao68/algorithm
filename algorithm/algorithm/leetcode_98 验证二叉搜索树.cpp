//
//  leetcode_98验证二叉搜索树.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/16.
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
    bool isvalidroot(TreeNode*root,int low,int high){
        if(!root) return true;//弹出条件
        if(root->val <= low ||root->val >= high) return false;
        return isvalidroot(root->left, low,root->val) &&isvalidroot(root->right,root->val, high);
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        return isvalidroot(root,root->left->val,root->right->val);
    }

};

//方法二：中序遍历判断
class Solution {
public:
    vector<long long > ans;
    void mid_rec(TreeNode* root){
        if(!root) return;
        mid_rec(root->left);
        ans.push_back(root->val);
        mid_rec(root->right);
    }

    bool isValidBST(TreeNode* root) {
        // 使用中序遍历，放到数组里判断。是否是升序的
        mid_rec(root);
        for(int i=1;i<ans.size();i++) {
            if(ans[i]<=ans[i-1]) return false;
        }
        return true;
    }
};
