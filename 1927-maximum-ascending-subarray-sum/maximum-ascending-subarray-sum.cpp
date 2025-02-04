class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int sum=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                sum+=nums[i];
            }else{
                sum+=nums[i];
                ans=max(ans,sum);
                sum=0;
            }
        }
        sum+=nums[n-1];
        ans=max(ans,sum);
        return ans;
    }
};