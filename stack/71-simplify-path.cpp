class Solution {
public:

//with stack as datastructure
    string simplifyPath(string path) {
        string current = "";
        stack <string> st;
        string ans = "";
        //adds / at the end 
        if(path.back() != '/'){
            path+='/';
        }

        for(int i = 0;i<path.length();i++){
            //handles /
            if(path[i] == '/'){
                //move back to previious element if ..
                if(current == ".."){
                    if(!st.empty())
                    st.pop();
                }
                //pushes current string if its not a . or empty string 
                else if(current != "." && current != ""){
                    st.push(current);
                }
                //resets current after /
                    current = "";    
            }    
            //builds string until / comes
            else{
                current += path[i];
            }
            }
//temp stack to reverse the order of elements
        stack<string> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        while(!temp.empty()){
            ans+='/';
            ans+=temp.top();
            temp.pop();
        }
        if (ans == ""){
            ans = "/";
        }
        return ans;
    }
};