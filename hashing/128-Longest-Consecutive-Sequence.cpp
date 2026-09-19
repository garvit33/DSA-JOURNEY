class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //set handles dup values 
        unordered_set<int> st;
        int maxcount = 0;
        //loop to store all values in set
        for(int x:nums){
            st.insert(x);
        }
        //checks every element i its next exists
        for(int x:st){
            int count = 0;
            int current;
            if(st.find(x-1) == st.end()){
                current = x;
                count = 1;
                //extends until consecutives are found
                while(st.find(current+1) != st.end()){
                    current++;
                    count++;
                }
            }
            //compares previous max and the current count
            maxcount = max(count,maxcount);
        }
        return maxcount;
    }
};