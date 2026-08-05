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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenhead = even;

//loop till even or next to even is not null
        while(even!=NULL && even->next!=NULL){ 
            //connects odd elements to odd list
            odd->next = even->next;
            //shifts odd pointer
            odd = odd->next;

            //connects even elements to even list
            even->next = odd->next;
            //shifts to even pointer
            even = even->next;
        }
        //connects even list to odd end 
        odd->next = evenhead;

    return head;
    }
};