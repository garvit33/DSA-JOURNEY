class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        //deques storing max and min of a window
        deque<int> maxq;
        deque<int> minq;
        int left = 0;
        int longest = 0;
        //right pointer
        for(int right = 0;right<nums.size();right++){
            //monotonic deque for always keeping max element of a window at front
            while(!maxq.empty() && nums[right]>nums[maxq.back()]){
                maxq.pop_back();
            }
            maxq.push_back(right);

            //monotonic deque for always keeping in element of a window at front
            while(!minq.empty() && nums[right]<nums[minq.back()]){
                minq.pop_back();
            }
            minq.push_back(right);


            //shrinks window while window is not valid max-min>limit
            while(nums[maxq.front()] - nums[minq.front()] > limit){
                //removes left index from max and min if it exists in deques
                if(left == maxq.front()){
                    maxq.pop_front();
                }
                if(left == minq.front()){
                    minq.pop_front();
                }
                left++;
            }
            // tracks longest
            longest = max(longest,right-left+1);


        }
                                                    
        return longest;
    }
};
