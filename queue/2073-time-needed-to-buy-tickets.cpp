class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int front = 0;
        int ans = 0;
        //while targeted element doesnt become 0
        while(tickets[k]>0){
            //if current front is more than 0 reduce is frequency
            if(tickets[front]>0){
            tickets[front]--;
            //+1 sec
            ans++;
            }
            //moving front circularly in a loop
            front = (front+1)%tickets.size();
        }
        return ans;
    }
};