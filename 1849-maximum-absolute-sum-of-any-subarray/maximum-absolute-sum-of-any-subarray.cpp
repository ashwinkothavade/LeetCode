class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // int n=nums.size();
        // int maxsum=0;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         maxsum=max(maxsum,abs(sum));
        //     }
        // }
        // return maxsum;
        int n=nums.size();
        int prefix=0;
        int minprefix=0;
        int maxprefix=0;
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            minprefix=min(minprefix,prefix);
            maxprefix=max(maxprefix,prefix);
        }
        return maxprefix-minprefix;
    }
};