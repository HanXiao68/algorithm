//
//  leetcode_116 填充每个节点的下一个右侧节点指针.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/20.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
// 就是层序遍历。指针连起来
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);
// 每一层连起来。上一层最后一个与下一层第一个之间的关系不用管。
        while(q.size()){
              
                int sz = q.size();
                for(int i=0;i<sz;i++){
                     Node* temp = q.front();q.pop();
                     if(i<sz-1) temp->next = q.front();
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
            
            
        }
        return root;
    }
};
