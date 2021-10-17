//
//  leetcode_106 从中序和后序遍历中构造二叉树.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/17.
//中序：左 根  右
//后续：左 右  根

#include<vector>

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
    TreeNode* buildTree(vector<int>& m, vector<int>& p) {
        TreeNode* root = new TreeNode(p[(p.size()-1)]);
        
        vector<int> l_m,r_m,l_p,r_p;
        int i;
        for(i=0;i<m.size();i++){
            if(m[i] == p[(p.size()-1)]) break;
            l_m.push_back(m[i]);
            l_p.push_back(p[i]);
        }
        i++;
        for(;i<m.size();i++){
            r_m.push_back(m[i]);
            r_p.push_back(p[i-1]);
        }
        
        root->left = buildTree(l_m, l_p);
        root->right = buildTree(r_m,r_p);
        
        return root;
    }
};
int main(){
    
    
    
    return 0;
}
