class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> map;
        vector<int> ans;
    //loops for array
        for(int i = 0;i<nums2.size(); i++){
            //assigns greater element to eligible elements waitng in stack and pops once assigned
            while(!st.empty() && st.top() < nums2[i]){
                map[st.top()] = nums2[i];
                st.pop();
            }
            //push elements
                st.push(nums2[i]);
            }
            //assigns -1 to the elements which has no greater in map
            while(!st.empty()){
                map[st.top()] = -1;
                st.pop();
            }
            //prepares ans array;
            for(int j = 0; j<nums1.size();j++){
                ans.push_back(map[nums1[j]]);
            }
            return ans;
        }
};