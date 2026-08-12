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
//function to detect cycle using floyds algo
    ListNode *floyd(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return slow;
            }
        }
        return NULL;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = floyd(head);
        //returns null if no cycle
        if (fast == NULL){
            return NULL;
        }
        //finds intersection point
        while (slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};