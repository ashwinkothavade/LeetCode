class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    if((i*j)%k==0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};