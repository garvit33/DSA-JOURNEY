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
    ListNode* swapPairs(ListNode* head) {
        //returns head if list is empty 
        if (head==NULL){
            return head;
        }
        ListNode* first = NULL;
        ListNode* second = NULL;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* PrevPair = &dummy;
        ListNode* NextPair = NULL;

    //loop while there is a pair available to swap    
        while(PrevPair->next!=NULL && PrevPair->next->next!=NULL){
            
            //stores first and shifts to next pairs first
            first = PrevPair->next;

            //stores second and shifts to next pairs second
            second = first->next;

            //stores starting of next pair
            NextPair = second->next;

            //connects prev to second basically swapping
            PrevPair->next = second;
        
            //swaps first and second
            second->next = first;

            //connects remaining pairs
            first->next = NextPair;

            //shifts to previous of next pair
            PrevPair = first;
        }
        return dummy.next;
        
    }
};