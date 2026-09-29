class Solution {
public:

    int solve(int n,vector<int>& dp){
        //base cases
        if(n==0)return 1;
        if(n==1)return 1;

        //if we have stored value for current n than we use it
        if(dp[n]!=-1)return dp[n];

        //calculates and stores value in dp
        dp[n] = solve(n-1,dp)+solve(n-2,dp);

        //return calculated value
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
        
    }
};