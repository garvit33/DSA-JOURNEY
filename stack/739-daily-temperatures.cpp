class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size(),0);
        
//monotonic stack
//loop traversing each element
        for(int i=0;i<temperatures.size();i++){
            //roop checking if element is grater with each waiting element in stack
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                ans[st.top()] = i - st.top();
                st.pop();
                }
                //pushes into stack 
            st.push(i);
        }
        return ans;
    }
};