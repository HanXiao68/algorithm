//
//  leetcode_105 从前序遍历和中序遍历构建二叉树.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/17.
//
//前序： 根 左   右
//中序： 左 根  右
#include <vector>
#include <iostream>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() != inorder.size()) return nullptr;
        if(inorder.size() ==0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        vector<int> l_p,r_p,l_m,r_m;
        int i;
        for( i = 0;i<inorder.size();i++){
            if(preorder[0] == inorder[i]) break;
            l_p.push_back(preorder[i+1]);
            l_m.push_back(inorder[i]);
        }
        i++;
        for(;i<inorder.size();i++){
            r_p.push_back(preorder[i]);
            r_m.push_back(inorder[i]);
        }
        root->left = buildTree(l_p,l_m);
        root ->right = buildTree(r_p,r_m);
//        for(auto x:l_p) cout<<x<<" ";
//        cout<<endl;
//        for(auto x:r_p) cout<<x<<" ";
//        cout<<endl;
//        for(auto x:l_m) cout<<x<<" ";
//        cout<<endl;
//        for(auto x:r_m) cout<<x<<" ";
//        cout<<endl;
        return root;
    }
};

int main(){
    Solution s;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    s.buildTree(preorder, inorder);
}
