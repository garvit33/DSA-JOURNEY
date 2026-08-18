class Solution {
public:
//helper function to concatenate string 
    string concatenate(int c,string currstr){
        string str;
        for(int i = 0;i<c;i++){
            str+=currstr;
        }
        return str;
    }
    string decodeString(string s) {
        stack<int> coefficient;
        stack<string> stringstack;
        int current = 0;  
        string currstr = ""; 
        //loop traversing string 
        for(int i = 0;i<s.length();i++){
            //if meets [ saves the coefficient and string
            if(s[i] == '['){
                coefficient.push(current);
                stringstack.push(currstr);
                current = 0;
                currstr = "";

            }
            //if encounter ']' calculates curr string and pops used values
            else if(s[i] == ']' ){
                current = coefficient.top();
                string prevstr = stringstack.top();
                currstr = prevstr + concatenate(current,currstr);
                coefficient.pop();
                stringstack.pop();
                current = 0;
            }
            //calculates coffecient and saves it 
            else if(isdigit(s[i])){
                current = current*10 + (s[i] - '0');
            }
            //appends currstr when we encounter a string
            else{
                currstr += s[i]; 
            }

        }
        
        return currstr;
    }
}; 