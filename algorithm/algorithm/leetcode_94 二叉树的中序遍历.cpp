////
////  leetcode 94 二叉树的中序遍历.cpp
////  algorithm
////
////  Created by 韩霄 on 2021/10/16.
////
//
//#include <stdio.h>
//#include <vector>
//
//using namespace std;
//
//struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
//class Solution {
//public:
//    vector<int> res;
//    
//    void mid_reverse(TreeNode* root){
//        if(!root) return;
//        
//        mid_reverse(root->left);
//        res.push_back(root->val);
//        mid_reverse(root->right);
//    }
//    vector<int> inorderTraversal(TreeNode* root) {
//        if(! root) return res;
//        mid_reverse(root);
//        
//        return res;
//    }
//};
//int main(){
//    
//    
//    
//    return 0;
//}
