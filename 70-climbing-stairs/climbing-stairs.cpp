class Solution {
    int func(int i,vector<int>&dp){
        if(i==1)return 1;
        if(i==2)return 2;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=func(i-1,dp)+func(i-2,dp);
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return func(n,dp);
    }
};