class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> s;
        int minimum = *min_element(nums.begin(),nums.end());
        int maximum = *max_element(nums.begin(),nums.end());

        for (int i = minimum;i<maximum;i++){
            s.insert(i);
        }
        for(int j =0;j<nums.size();j++){
            if(s.count(nums[j])){
                
            }

        }
    }
};