class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }
        vector<long long>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        long long ans=0;
        for(int i=0;i<n-1;i++){
            if(prefix[i]>=totalsum-prefix[i+1]+nums[i+1]){
                ans++;
            }
        }
        return ans;
    }
};