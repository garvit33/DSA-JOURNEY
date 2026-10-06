class Solution {
public:

    void solver(int remaining,vector<int>& ans,vector<vector<int>>& allsub,vector<int>& candidates,int start){
        //base case if pair found
        if(remaining == 0){
            allsub.push_back({ans});
            return;
        }
        
        //runs for every index as a base 
        for(int i = start;i<candidates.size();i++){
            //include only if upocoming number can fit
            if(remaining<candidates[i])continue;   

            //include 
            ans.push_back(candidates[i]);

            solver(remaining-candidates[i],ans,allsub,candidates,i);
 
            //exclude
            ans.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> allsub;
        vector<int> ans;

        solver(target,ans,allsub,candidates,0);

        return allsub;
    }
};