class MyCircularDeque {
public:
    vector<int> dq;
    int front;
    int rear;
    int size;
    int capacity;

    MyCircularDeque(int k) {
        dq.resize(k);
        front = 0;
        rear = 0;
        size = 0;
        capacity = k;
    }
    
    bool insertFront(int value) {
        if(!isFull()){
        //shits front to previous index 
        front = ((front-1)+capacity)%capacity; 
        dq[front] = value;
        size++;
        return true;
        }
        else{
            return false;
        }
    }
    
    bool insertLast(int value) {
        if(!isFull()){
        dq[rear] = value;
        //shifts rear to next index where new element will come
        rear = (rear+1)%capacity;
        size++;
        return true;
        }
        else{
            return false;
        }
    }
    
    bool deleteFront() {
        if(!isEmpty()){
        //shifts front one step ahead and reduce size
        front = (front+1)%capacity;
        size--;
        return true;
        }
        else{
            return false;
        }
    }

    bool deleteLast() {
        if(!isEmpty()){
        //shifts rear one step back and reduce size
        rear = ((rear-1)+capacity)%capacity;
        size--;
        return true;
        }
        else{
            return false;
        }
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        else{
            //point to current front 
            return(dq[front]);
        }
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        else{
            //rear points to index where next rear will come so we return rear - 1 index by circular logic
            return(dq[(rear-1+capacity)%capacity]);
        }
    }
    
    bool isEmpty() {
        if(size == 0){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isFull() {
        if(size==capacity){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */