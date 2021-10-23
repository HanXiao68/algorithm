//
//  200 1265 逆序打印不可变链表.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/23.
//

/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
int count = 0;
    void printLinkedListInReverse(ImmutableListNode* head) {
         if (head == nullptr)
            return;
        ImmutableListNode* fast_begin = head->getNext();
        while (fast_begin != nullptr) {
            ImmutableListNode* slow = head;
            ImmutableListNode* fast = fast_begin;
            while (fast != nullptr) {
                slow = slow->getNext();
                fast = fast->getNext();
            }
            slow->printValue();
            fast_begin = fast_begin->getNext();
            cout<<++count<<endl;
        }
        head->printValue();
    }
};
