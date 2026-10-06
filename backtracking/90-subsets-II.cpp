class Solution {
public:

    void solver(int i,vector<int>& ans,vector<vector<int>>& allsub,vector<int>& nums){

        if(i == nums.size()){
            allsub.push_back({ans});
            return;
        }

        ans.push_back(nums[i]);
        solver(i+1,ans,allsub,nums);

        ans.pop_back();


        // skips the duplicate indices so once a value is exclujded it doesnt gets included
        int idx = i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1])idx++;
        solver(idx,ans,allsub,nums);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> allsub;
        vector<int> ans;

        solver(0,ans,allsub,nums);
        return allsub;
    }
};