class Solution {
public:
    vector<vector<int>> allperms;


    void solver(int index,vector<int>& nums){

        // stores used values in a following recursion level
        unordered_set<int> used;

        // checks if already the value exists in set if yes skip that iteration
        if(index == nums.size()){
            allperms.push_back({nums});
            return;
        }
        
        for(int i = index;i<nums.size();i++){
            if(used.count(nums[i]))continue;
            used.insert(nums[i]);

            swap(nums[i],nums[index]);

            solver(index+1,nums);

            swap(nums[i],nums[index]);
            
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        solver(0,nums);

        return allperms;
    }
};