class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            int lowerlevel=lower-nums[i];
            int upperlevel=upper-nums[i];
            auto lind=lower_bound(nums.begin()+i+1,nums.end(),lowerlevel);
            auto uind=upper_bound(nums.begin()+i+1,nums.end(),upperlevel);
            ans+=(uind-lind);
       }
       return ans;
    }
};