class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-2;i++){
            double sum=nums[i]+nums[i+2];
            if(sum==(double)nums[i+1]/2)ans++;
        }
        return ans;
    }
};