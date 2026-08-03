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
        //dummy node for edge case
        ListNode dummy(0);
        //connected head to the dummy
        dummy.next = head;
        
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
//shifting fast n gap away from slow
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
//loop till fast reaches null
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        //deletes node and connects to the list again
        slow->next = slow->next->next;
        return dummy.next;        
    }
};