//
//  leetcode_2两数相加.cpp
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = 0;
        ListNode* newhead = new ListNode(0);
        ListNode* nownode = newhead;

        while(l1 ||l2 ||carry){
            sum = (l1?l1->val:0) + (l2?l2->val:0)  +carry;

            carry = sum/10;
            ListNode* node  =new ListNode(sum%10);
            nownode->next = node;//新节点接上去
            nownode  =nownode->next;

            l1 =l1?l1->next:nullptr;
            l2 = l2?l2->next:nullptr;
        }
        return newhead->next;
    }
};
