class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //monotonic stack
        stack<int> st;
        int n = nums.size();
        //ans array
        vector<int> ans(n,-1);
        //loops the array twice
        for (int i =0;i<(n*2);i++){
            //maintains the circular traversal
            int current = nums[i%n];
            //checks is top index of stack is smaller then current
            while(!st.empty() && nums[st.top()]<current){
                ans[st.top()] = current;
                st.pop();
            }
            //pushes valid candidate into stack
            if(i<n){
            st.push(i%n);
            }
        }
        return ans;
    }
};