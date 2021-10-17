////
////  leetcode 95 不同的二叉搜索树.cpp
////  algorithm
////
////  Created by 韩霄 on 2021/10/16.
////
////生成的结果的个数是卡特兰数
//
//#include <vector>
//
//using namespace std;
//
//struct TreeNode {
//    int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  };
//
//class Solution {
//public:
//    vector<TreeNode*> res;
//    vector<TreeNode*> generateTrees(int n) {
//        if(n==0) return {};
//        dfs(1,n);
//        return res;
//    }
//    vector<TreeNode*> dfs(int l,int r){
//        if(l>r) return {nullptr};
//        for(int i=l;i <= r;i++){
//            auto left = dfs(0,i-1);auto right = dfs(i+1,r);
//            for(auto l:left){
//                for(auto r:right){
//                    auto root = new TreeNode(i); //每次有新的结果都要new根节点。
//                    root->left = l;root->right = r;
//                    res.push_back(root);
//                }
//            }
//        }
//        return res;
//    }
//};
//
//
//
//
//
//
//
//
