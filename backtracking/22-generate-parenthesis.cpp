class Solution {
public:
        vector<string> ans;
        int n;
    void backtrack(int open,int close,string current){
        //pushes the string if its a valid answer with max opening and close brackets and return to previous step to explore all possible answers
        if(open == n && close == n){
            ans.push_back(current);
            return;
        }
        //recursively explores all possibilities if  open <n at current
        if(open<n){
            current+="(";
            backtrack(open+1,close,current);
            current.pop_back();
        }
        //recursively explores all possibilities if  open >close at current
        if(open>close){
            current+=")";
            backtrack(open,close+1,current);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        this->n = n;
        //calls the backtrack function
        backtrack(0,0,"");
        return ans;
    }
};