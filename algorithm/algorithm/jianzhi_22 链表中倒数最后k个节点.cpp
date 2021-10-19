//
//  jianzhi_22 链表中倒数最后k个节点.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//

#include <stdio.h>

/**
 * struct ListNode {
 *    int val;
 *    struct ListNode *next;
 *    ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pHead ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* head, int k) {
        // write code here
        ListNode* first = head;
        ListNode* second = head;
        while(k--)  {
            if(!first) return nullptr;
            first = first->next;
        }
        while(first){
            first = first->next;
            second = second->next;
        }
        return second;
    }
};
