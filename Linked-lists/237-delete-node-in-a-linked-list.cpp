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
    void deleteNode(ListNode* node) {
        //replacing current node value with next

        node->val = node->next->val;
        //connecting current node to next node of next
        node->next = node->next->next;
    }
};