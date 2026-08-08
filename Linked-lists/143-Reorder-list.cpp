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
    void reorderList(ListNode* head) {
        //created slow and fast pointers for finding middle 
        ListNode* fast = head->next;
        ListNode* slow = head;
        ListNode* first = head;
        //loop for finding middle 
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast=fast->next->next;
        }
        //shift curr to the next node of slow(middle)
        ListNode* curr = slow->next;
        //split at middle
        slow->next = NULL;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        //reversing the second list 
        while (curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;    
            curr = next;
        }
        ListNode* second = prev;
        ListNode* firstnext = NULL;
        ListNode* secondnext = NULL;
        //merging nodes of first and reversed second list alternatively
        while(second!=NULL){
            firstnext = first->next;
            secondnext = second->next;
            first->next=second;
            second->next = firstnext;
            first = firstnext;
            second = secondnext;
        }
        return;
        
    }
};
