class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int currentsum = 0;
        //stores prefix sum frequency
        unordered_map<int,int> mp;
        int count = 0;
        mp[0] = 1;
        //traverses array
    for(int i =0;i<nums.size();i++){
        //adds element to current sum
        currentsum+=nums[i];
        //checks if the needed element to build a array whose sum = k is present in mp or not
        if(mp.find(currentsum-k) != mp.end()){
            count += mp[currentsum-k];
        }
        //increases prefix sum frequency
            mp[currentsum]++;
        
    }
    return count;
    }
};