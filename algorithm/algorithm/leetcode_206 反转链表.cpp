////
////  leetcode_206 反转链表.cpp
////  algorithm
////
////  Created by 韩霄 on 2021/10/21.
////
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* temp = nullptr;
        ListNode* pre = head;
        while(pre){
            ListNode* t = pre->next;
            pre->next = temp;
            temp = pre;
            pre = t;
        }
        return temp;
    }
};
