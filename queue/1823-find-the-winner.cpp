class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int> dq;

        //intialize deque with n elements
        for(int i =1;i<=n;i++){
            dq.push_back(i);
        }

        //runs while 1 element remains 
        while(dq.size()!=1){

            //pushes k-1 elements from back to front 
            for(int i =0;i<k-1;i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
            //pops every k element
            dq.pop_front();
        }

        //return the remaining element
        return dq.front();
    }

};