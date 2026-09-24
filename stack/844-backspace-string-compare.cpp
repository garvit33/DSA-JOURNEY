class Solution {
public:
    bool backspaceCompare(string s, string t) {
        //stacks for both strings
        stack<char> st1;
        stack<char> st2;
        
        //initializing stack for s if # comes we remove a element
        for(char x:s){
            if(x == '#'){
                if(!st1.empty()){
                    st1.pop();
                }
            }

            else{
                st1.push(x);
            }
        }
    //initializing stack for t if # comes we remove a element
        for(char y:t){
            if(y == '#'){
                if(!st2.empty()){
                    st2.pop();
                }
            }
            else{
                st2.push(y);
            }
        }
        //if both stacks size is not same
        if(st1.size() != st2.size()){
            return false;
        }
        //checks top constantly to check the whole stack
        while(!st1.empty()){
            if(st1.top() != st2.top()){
                return false;
            }
            st1.pop();
            st2.pop();
        }
    return true;
    }
};