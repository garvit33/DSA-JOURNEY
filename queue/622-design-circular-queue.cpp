class MyCircularQueue {
public:
//decalring a array and variables
        vector<int> arr;
        int front;
        int rear;
        int size;
        int capacity;
    MyCircularQueue(int k) {
        //initializing variables and the array
        arr.resize(k);
        capacity = k;
        front = 0;
        rear = 0;
        size = 0;
    }
    
    bool enQueue(int value) {
        if(!isFull()){
        arr[rear] = value;
        size++;
        //main circular logic
        rear = (rear+1)%capacity;
        return true;
        }
        else{return false;}
    }
    
    bool deQueue() {
        if(!isEmpty()){
            front = (front+1)%capacity;
            size--;
            return true;
        }
        else{return false;}
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        else{
        return arr[front];
        }
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        else{
            //to avoid 0 edge case we do this and -1 for the current rear
        return arr[(rear-1+capacity) % capacity];
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
        if(size == capacity){
            return true;
        }
        else{
            return false;
        }
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */