class Solution { 
public:

    void solver(int i, vector<int>& nums, vector<vector<int>>& allsub, vector<int>& ans){
        
        //if hit base case which is going to n level
        if(i == nums.size()){
            allsub.push_back({ans});
            return;
        }

        //inclusding element solver 
        ans.push_back(nums[i]);
        solver(i+1,nums,allsub,ans);

        //backtrack
        ans.pop_back();

        //excluding element solver
        solver(i+1,nums,allsub,ans);

    }


    vector<vector<int>> subsets(vector<int>& nums) {

        // stores all subsets
        vector<vector<int>> allsub;

        //stores current subsets at a level i 
        vector<int> ans;
        //recursion function
        solver(0,nums,allsub,ans);

        return allsub;
    }
};