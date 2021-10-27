//
//  leetcode_234 判断是否是回文链表.cpp
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
    bool isPalindrome(ListNode* head) {
        if(!head) return true;

        // 用栈，把链表中的数反过来，存进去
        stack<int> st;

        ListNode* cur = head;
        while(cur){
            st.push(cur->val);
            cur = cur->next;
        }
        while(head){
            if(head->val != st.top()) return false;
            head = head->next;
            st.pop();
        }
        return true;
    }
};
