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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* previoushead = &dummy;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        //marking curr and its previous node
        for (int i = 1;i<left;i++){
            previoushead = curr;
            curr = curr->next;
        }
        ListNode* reversedstart = curr;
        //length of nodes that should be reversed
            int k = (right-left)+1;
//reversing loop till k 
        for(int j=0;j<k;j++){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        //connencts head to prev
        previoushead->next = prev;
        //connects reversed end to remaining list
        reversedstart->next = curr;
        return dummy.next;
        }
        
};