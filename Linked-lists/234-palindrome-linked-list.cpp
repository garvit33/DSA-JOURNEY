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
        ListNode* fast = head;
        ListNode* slow = head;
        //finding middle
        while (fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = slow;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        //reversing the list after middle
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* first = head;
        ListNode* second = prev;
        //checking first list elements with second reversed list
        while (second!=NULL){
            if(first->val == second->val){
                first = first->next;
                second = second->next;
            }
            else{
                return false;
            }
        } 
        return true;     
    }
};