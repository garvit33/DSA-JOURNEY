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
    ListNode* reverseList(ListNode* head) {
        //initialize the next pointer as null
        ListNode* next = NULL;
        //initialize the current pointer as head
        ListNode* curr = head;
        //initialize the previous pointer as null
        ListNode* prev = NULL;
//runs till current becomes null
        while(curr!=NULL){
            //makes the next pointer point to next element
            next = curr->next;
            //reverse the pointer connection to the previous pointer
            curr->next = prev;
            //move previous to current
            prev = curr;
            //move current to next
            curr = next;
            
    }
    //returns head

        return prev;
    }
};