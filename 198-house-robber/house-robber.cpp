class Solution {
    int func(int index,vector<int>&nums,vector<int>&dp){
        if(index==0){
            return nums[0];
        } if(index==1){
            return max(nums[0],nums[1]);
        }
        if(dp[index]!=-1)return dp[index];
        return dp[index]=max(func(index-1,nums,dp),func(index-2,nums,dp)+nums[index]);

    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return func(n-1,nums,dp);
    }
};