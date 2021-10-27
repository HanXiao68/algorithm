//
//  leetcode_142 环形链表入环节点.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

         ListNode * fast = head;
         ListNode* slow = head;
         while(fast){
             if(fast->next ==nullptr) return nullptr;
             else   fast = fast->next->next;
             slow = slow->next;
             if(fast == slow) {
                fast = head;
                while(fast !=slow){
                    fast =fast->next;
                    slow = slow->next;
                }
                return fast;
            }
         }
        return nullptr;
    }
};
