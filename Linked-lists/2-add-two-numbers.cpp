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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* first = l1;
            ListNode* second = l2;
            ListNode dummy(0);
            ListNode* neww = &dummy;
            int carry = 0;
            int sum = 0;
            int digit = 0;
//loop while both pointers are not null
            while(first!=NULL || second!=NULL || carry!=0){
                //carries carry
                sum=carry;
                //adds first node's value
                if(first!=NULL){
                    sum+=first->val;
                    first = first->next;
                }
                //adds second node's value
                if(second!=NULL){
                    sum+=second->val;
                    second = second->next;
                }
                //calculates the digit and carry
                digit = sum%10;
                carry = sum/10;
                //adds digit in a new node
                neww->next = new ListNode(digit);
                neww = neww->next;
                sum=0;
            }
            
            return dummy.next;
    }
};