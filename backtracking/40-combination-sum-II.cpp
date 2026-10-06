class Solution {
public:

    void solver(vector<int>& candidates, int remaining,vector<vector<int>>& allsums,vector<int>& curr,int start){

        if(remaining == 0){
            allsums.push_back({curr});
            return;
        }

        for(int i = start;i<candidates.size();i++){

            if(i>start && candidates[i] == candidates[i-1])continue;

            if(candidates[i]>remaining)break;

            curr.push_back(candidates[i]);

            solver(candidates,remaining-candidates[i],allsums,curr,i+1);

            curr.pop_back();    
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> allsums;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());


        solver(candidates,target,allsums,curr,0);

        return allsums;
    }
};