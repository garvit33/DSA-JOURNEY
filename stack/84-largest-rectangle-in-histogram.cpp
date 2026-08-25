class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int bestarea = 0;
        vector<int>leftboundary(n,-1);
        vector<int>rightboundary(n,n);
        
        for(int i = 0;i<n;i++){
            //monotonic stack logic for next and previous smaller 
            while(!st.empty() && heights[st.top()]>=heights[i]){
                //stores right boundary
                rightboundary[st.top()] = i;
                st.pop();
            }
            //stores left boundary 
                if(!st.empty()){
                    leftboundary[i] = st.top();
                }
                //pushes element to stack for finding their boundaries
            st.push(i);
        }
        //calculates area for every height 
        for(int j = 0;j<n;j++){
            int width = rightboundary[j] - leftboundary[j] -1;
            int area = heights[j] * width;
            bestarea = max(area,bestarea);
        }
    return bestarea;
    }
}; 