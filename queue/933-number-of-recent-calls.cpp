class RecentCounter {
public:
//queue
        queue<int> q;
        //initializes the queue
    RecentCounter() {
    }
    //ping function
    int ping(int t) {
        //pushes the request with its time
    q.push(t);
    //pops all elements from front if it doesnt fits in t-3000 range;
    while(!q.empty()&&q.front()<t-3000){
        q.pop();
    }
    //returns number of services 
    return q.size();      
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */