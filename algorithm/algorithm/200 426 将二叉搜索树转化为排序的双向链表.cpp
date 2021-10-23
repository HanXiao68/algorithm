//
//  200 426 将二叉搜索树转化为排序的双向链表.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/23.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
     Node *currNode;
public:
    Node* treeToDoublyList(Node* root) {
        Node dummyHead(0, 0, root);
        currNode = &dummyHead;
        if(root)
        {
            inOrdTra(root);
            currNode->right = dummyHead.right;
            dummyHead.right->left = currNode;
        }
        return dummyHead.right;
    }
    void inOrdTra(Node *t)
    {
        if(t)
        {
            inOrdTra(t->left);
            
            currNode->right = t;
            t->left = currNode;
            currNode = t;
            
            inOrdTra(t->right);
        }
    }
};
