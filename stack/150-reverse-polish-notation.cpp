class Solution {
public:
//calculates the a b with the given operand
    int calculate(int a,int b,char op){
        if(op == '/'){return a/b;}
        if(op == '*'){return a*b;}
        if(op == '+'){return a+b;}
        if(op == '-'){return a-b;}
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a = 0;
        int b = 0;
        char op;
        for(int i = 0;i<tokens.size();i++){
            //checks if there is a operand and calculates them
            if(tokens[i] == "/" || tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "-"){   
                op = tokens[i][0];
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                st.push(calculate(a,b,op));
            }
            //pushes values
            else{
                st.push(stoi(tokens[i]));
                
            }

        
    }
    return st.top();
    }
};