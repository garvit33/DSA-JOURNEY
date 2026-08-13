/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //map that stores original node and copy node
        unordered_map<Node*,Node*> mp;
        Node* curr = head;
        //stores each original nodes copy into the map 
        while(curr!=NULL){
            Node* newNode = new Node(curr->val);
            mp[curr] = newNode;
            curr = curr->next;
        }
        curr = head;
        //assigns pointers of original node to the copy nodes using maps 
        while(curr!=NULL){
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
            }
            //returns new node assigned to original head
        return head == NULL?NULL:mp[head];
    }
};