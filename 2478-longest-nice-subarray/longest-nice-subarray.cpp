class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxlen=1;
        for(int i=0;i<n;i++){
            int a=nums[i];
            for(int j=i+1;j<n;j++){
                if((a&nums[j])==0){
                    a|=nums[j];
                    maxlen=max(maxlen,j-i+1);
                }else{
                    break;
                }
            }
        }
        return maxlen;
    }
};