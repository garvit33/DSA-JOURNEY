class LRUCache {
    //creates structure of doubly linked list nodes
        struct Node {
            int key;
            int value;
            Node* prev;
            Node* next;
        Node(int k,int v){
            key = k;
            value = v;
            prev = next = NULL;
        }
        };
//initialize head and tail dummy pointers
            Node* head = new Node(0,0);
            Node* tail = new Node(0,0);

        int capacity;
//map for storing nodes respecting to its key
        unordered_map <int,Node*> m;
//helper function to add node just nex to the head
        void addnode (Node* newnode){
            Node* oldnext = head->next;
            head->next = newnode;
            oldnext->prev = newnode;
            newnode->next = oldnext;
            newnode->prev = head;
        }
//helper function to del node
        void delnode(Node* oldnode){
            Node* oldprev = oldnode->prev;
            Node* oldnext = oldnode->next;
            oldprev->next = oldnext;
            oldnext->prev = oldprev;
        }

public:
//initializes capacity and the ddl
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
//get function 
    int get(int key) {
        //if key not found 
        if(m.find(key) == m.end()){
            return -1;
        }
        Node* ansnode = m[key];
        int ans = ansnode->value;
        //deletes the existing node
        m.erase(key);
        delnode(ansnode);
        //insert node at next of head
        m[key] = ansnode;
        addnode(ansnode);
        //returns value of key->val
        return ans;
    }
    //function for insertion(put)
    void put(int key, int value) {
        //if there is already key existing
        if(m.find(key)!=m.end()){
            Node* oldnode = m[key];
            //deletes already existing node and key from map
            delnode(oldnode);
            m.erase(key);
        }
        //if size exceeds capacity deletes 
        if(m.size() == capacity){
            m.erase(tail->prev->key);
            delnode(tail->prev);
        }
        //adds the node to the heads next
        Node* newnode = new Node(key,value);
        addnode(newnode);
        m[key] = newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */