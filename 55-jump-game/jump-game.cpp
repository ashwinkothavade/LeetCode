class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxjump=nums[0];
        int n=nums.size();
        if(maxjump==0&&n>1)return false;
        if(n==1)return true;
        for(int i=1;i<n;i++){
            if(i+nums[i]>maxjump){
                maxjump=i+nums[i];
            }
            if(maxjump>=n-1){
                return true;
            }
            if(maxjump<=i)return false;
        }
        return false;
    }
};