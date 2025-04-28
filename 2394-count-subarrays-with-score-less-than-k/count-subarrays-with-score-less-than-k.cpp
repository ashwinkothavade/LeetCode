class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        int i=0;
        int j=0;
        long long sum=0;
        long long temp=0;
        long long count=0;
        while(i<n){
            sum+=nums[i];
            temp=sum*(i-j+1);
            while(j<n&&temp>=k){
                count+=(n-i);
                // cout<<count<<endl;
                sum-=nums[j];
                j++;
                temp=sum*(i-j+1);
            }
            i++;
        }
        // cout<<count;
        return ((long long)n*(n+1))/2-count;
    }
};