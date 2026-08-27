class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
//main loop iterates num
        for(int i = 0;i<num.length();i++){
            //pops element if current element is smaller than each element in stack max k times
            while(!st.empty() && st.back()>num[i] && k>0){
                st.pop_back();
                k--;
            }  
            //push element into st
            st.push_back(num[i]); 
        }
        //if no such pair found manually remove elements from last of st remaining k times
            while(k>0){
                st.pop_back();
                k--;
            }
            //find first non zero pos
            int pos = st.find_first_not_of('0');
            //if no non zero position found 
            if(pos == string::npos){
                return "0";
            }
            //returns substring from first non zero occurence 
            else{
                return st.substr(pos);
            }
    }

};