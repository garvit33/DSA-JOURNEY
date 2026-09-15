class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for(int right = 0;right<nums.size();right++){
            //removes outdatd element from the window and queue
            if(!dq.empty() && right-k >= dq.front()){
                dq.pop_front();
            }
            //maintain the deque in descending order so the front is always largest for a window
            //monotonic 
            while(!dq.empty() && nums[dq.back()]<nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);
            //pushes answer when window size is valid
            if(right>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};