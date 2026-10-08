class Solution {
public:
        vector<string> ans;

    void solver(string& digits,vector<string>& map,int idx,string& curr){
        if(idx == digits.size()){
            ans.push_back(curr);
            return;
        }

        for(char c:map[digits[idx]-'0']){

            curr.push_back(c);

            solver(digits,map,idx+1,curr);

            curr.pop_back();

        }

    }
    vector<string> letterCombinations(string digits) {

        string curr;
        vector<string> map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        solver(digits,map,0,curr);

        return ans;
    }
};