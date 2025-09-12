class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        int res=0;
        vector<vector<int>>dp(k,vector<int>(k,0));
        for(int num:nums){
            num%=k;
            for(int prev=0;prev<k;prev++){
                dp[num][prev]=dp[prev][num]+1;
                res=max(res,dp[num][prev]);
            }
        }
        return res;
    }
};