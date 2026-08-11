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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //two pointers for both lists
        ListNode* first = headA;
        ListNode* second = headB;
        
//loop will stop once both intersects 
        while(first != second){
            //moves both pointers simultaneously and a pointer jumps to the other lists head if its reach to the null
            if(first == NULL){
                first = headB;
            }
            else{
                first = first->next;
            }
            if(second == NULL){
                second = headA;
            }
            else{
                second = second->next;
            }
        }
        //returns intersection point
    return first;
    }
};