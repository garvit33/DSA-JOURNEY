class StockSpanner {
public:
    stack<pair<int,int>> st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        //initial count for every element
        int count  = 1;
        //if latest element is greater than previous
        while(!st.empty() && price >= st.top().first){
            //we add the span of previous element to it
            auto top = st.top();
            count+=top.second;
            st.pop();
        }
        st.push({price,count});

        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */