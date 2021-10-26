//
//  leetcode_19 删除链表倒数第n个节点.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);  //哑节点
        if(!head)  return head;
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* q = dummy;
        while(n--)
        {
            if(q->next)
                q=q->next;
            else return nullptr;
        }

        while(q->next)
        {
           p= p->next;
           q= q->next;
        }
        p->next = p->next->next;  //删除p->next的节点
        return dummy -> next;
    
    }
};
