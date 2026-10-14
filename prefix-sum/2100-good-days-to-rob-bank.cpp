class Solution {
public:

    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> decreasing(n,0);
        vector<int> increasing(n,0);
        vector<int> ans;
        int count = 0;

        //calculates and store the number of decreaing security days in a array
        for(int i = 1;i<n;i++){
            if(security[i-1]>=security[i]){
                count++;
                decreasing[i] = count;
            }
            else{count = 0;}
        }
        count = 0;

        //calculates and store the number of increasing security days in a array
        for(int i = n-2;i>0;i--){
            if(security[i]<=security[i+1]){
                count++;
                increasing[i] = count;
            }
            else{
                count = 0;
            }
        }

        //checks each element for number of increasing and decreading security days before and after if valid i gets pushed
        for(int i = 0;i<n;i++){
            if(decreasing[i]>=time && increasing[i]>=time){
                ans.push_back(i);
            }
        }
        return ans;
    }
};