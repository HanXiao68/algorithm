//
//  leetcode 25 k个一组反转链表.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/25.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dum = new ListNode(-1);
        dum->next = head;
        ListNode* pre =  dum;
        ListNode* end  = dum;
        while(end->next){
            for(int i=0;i<k && end !=nullptr;i++){
                end = end->next;
            }
            if(end == nullptr) break;

            ListNode* start = pre->next;
            ListNode* next = end->next;
            end->next = nullptr;

            pre->next = reverse(start);
            start->next = next;
            pre = start;
            end = pre;
        }
        return dum->next;
    }
    ListNode* reverse(ListNode* head){
        ListNode* pre = new ListNode(-1);
        while(head){
            ListNode* t = head->next;
            head->next = pre;
            pre = head;
            head = t;
        }
        return pre;
    }
};
