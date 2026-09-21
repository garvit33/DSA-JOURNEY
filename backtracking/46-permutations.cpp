class Solution {
public:
    void perm(vector<int>& nums,int index,vector<vector<int>>& ans){
        //if a valid permutation is formed then oush to ans
        if(index == nums.size()-1){
            ans.push_back({nums});
            return;
        }
        //runs n-1 for evry index a
        for(int i = index;i<nums.size();i++){
            //swaps and make a new possible array
            swap(nums[index],nums[i]);
            //recursive function for remaining array
            perm(nums,index+1,ans);
            //back track 
            swap(nums[i],nums[index]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        perm(nums,0,ans);
        return ans;
    }
};