    class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_map<int,int> freq;
            for(int i = 0;i<nums.size();i++){
                freq[nums[i]]++;
            }
            if(freq.size()==nums.size()){
                return false;
            }
            return true;
        }
    };