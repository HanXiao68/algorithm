//
//  leetcode_23 合并k个升序链表.cpp
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        int start =0;int end =lists.size()-1;
        return mergeKLists( lists,start,end);
    }
    // 进行分治
   ListNode* mergeKLists( vector<ListNode*>& lists,int start,int end){
        if(end<=start) return lists[start];
       
        // 分治
        int mid = start+((end-start)>>1);
        ListNode *n1 = mergeKLists(  lists,start, mid);
        ListNode* n2 = mergeKLists(lists,mid+1,end);
        
        ListNode* res = mergeTwoLists(n1,n2);
      return  res;
    }
    // 常规二路归并
    ListNode* mergeTwoLists(ListNode*l1,ListNode*l2){
     
        ListNode*cur = new ListNode(-1);
        ListNode* temp= cur;
        while(l1 &&l2){
            if(l1->val <= l2->val){
                temp->next = l1;
                l1 = l1->next;
                temp =temp->next;
            }else{
            temp->next = l2;
            l2 = l2->next;
            temp =temp->next;
            }
        }
        if(l1) temp->next = l1;
        if(l2) temp->next = l2;

         return cur->next;
    }
};
