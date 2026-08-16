class MinStack {
public:
//creates two stacks st and minst
    stack<int> st;
    stack<int> minst;
    //initializes stacks
    MinStack() {}
    //push function
    void push(int value) {
        st.push(value);
        //if empty push the value
        if (minst.empty()){
            minst.push(value);
        } else {
            //pushes the minimum between value and top of minst
            int minimum = min(value, minst.top());
            minst.push(minimum);
        }
    }

    void pop() {
        //pops top from each stack
        st.pop();
        minst.pop();
    }

    int top() { return st.top(); }

    int getMin() { return minst.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */