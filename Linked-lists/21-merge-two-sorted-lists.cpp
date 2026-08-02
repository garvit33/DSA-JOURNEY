class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node acts as a fixed starting point of the merged list.
        ListNode dummy(0);

        // Tail always points to the last node of the merged list.
        ListNode* tail = &dummy;

        // Continue while both lists still have nodes.
        while (list1 != nullptr && list2 != nullptr) {

            // Pick the smaller node.
            if (list1->val <= list2->val) {

                // Attach list1's current node.
                tail->next = list1;

                // Move list1 forward.
                list1 = list1->next;
            }
            else {

                // Attach list2's current node.
                tail->next = list2;

                // Move list2 forward.
                list2 = list2->next;
            }

            // Move tail to the node we just attached.
            tail = tail->next;
        }

        // One list is finished.
        // Attach the remaining nodes of the other list.
        if (list1 != nullptr)
            tail->next = list1;
        else
            tail->next = list2;

        // Return the actual head of the merged list.
        // We return dummy.next because dummy itself is not part of the answer.
        return dummy.next;
    }
};