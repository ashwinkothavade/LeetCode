class Solution {
    int func(int i, vector<int>& cost, int n,vector<int>&dp) {
        if(i >= n) return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=cost[i] + min(func(i+1, cost, n,dp), func(i+2, cost, n,dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return min(func(0, cost, n,dp), func(1, cost, n,dp));
    }
};
