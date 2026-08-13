class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maximum = *max_element(nums.begin(),nums.end());
        int minimum = *min_element(nums.begin(),nums.end());
        int j = 0;
        vector<int> ans;

        for (int i=minimum; i<=maximum; i++){
            if(j<nums.size()&&nums[j] == i){
                j++;
            }
            else{
                ans.push_back(i);
            }
        }
        return ans;
    }
};