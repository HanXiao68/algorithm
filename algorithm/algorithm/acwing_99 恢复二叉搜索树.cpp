//
//  acwing_99 恢复二叉搜索树.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/17.
//
//只有两个数被交换了。可能是相邻的。也可能不是相邻的
//关键在于找出中序遍历的逆序对的两个数。
//这道题要求On的时间复杂度。所以考的是morris遍历。


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
    void recoverTree(TreeNode* root) {
//        逆序的第一个节点，第二个节点，前导节点
        TreeNode* first = nullptr,*second,*last =nullptr;
        while(root){
            if(!root->left){
                if(last &&last->val >root ->val){
//                    如果first还没有赋值，那么首次赋值
                    if(!first) first = last,second = root;
//                    如果已经赋值过了，那么不用给first赋值，直接覆盖second的值
                    else second = root;
                }
//                指针往下移动，继续遍历右子树
                last = root;
                root = root->right;
            }else{
                auto p = root->left;
                while(p->right && p->right !=root)  p = p->right;
                if(!p->right ) p->right =root,root = root->left;
                else{
                    p->right = nullptr;
                    if(last && last->val >root->val){
                        if(!first) first = last,second = root;
                        else second = root;
                    }
                    last = root;
                    root=root->right;
                }
            }
        }
        swap(first->val,second->val);
    }
};
