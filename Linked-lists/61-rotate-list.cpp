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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        ListNode* curr = head;
        int n = 0;
        //counts the length of list 
        while(curr!=NULL){
            curr = curr->next;
            n++;
        }
        //edge case
        if(n == 0){
            return head;
        }
        //number of rotation needed
            k = k%n;

        if(k==0){
            return head;
        }
        //shiftsfast to k steps further to slow 
        for (int i=0; i<k;i++){
            fast = fast->next;
        }
        //move fast and slow to k steps before fast
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        //links k number of nodes from last and attach to newhead 
        ListNode* newhead = NULL;
        newhead = slow->next;
        slow->next = NULL;
        fast->next = head;
        
    return newhead;
    }
};