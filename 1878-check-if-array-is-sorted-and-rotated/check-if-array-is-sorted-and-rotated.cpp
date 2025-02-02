class Solution {
public:
    bool check(vector<int>& nums) {
        int ind=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                ind=i;
                break;
            }
        }
        if(ind==INT_MAX)return true;
        vector<int>temp(n,0);
        for(int i=0;i<n;i++){
            temp[i]=nums[(i+ind+1)%n];
        }
        for(int i=0;i<n-1;i++){
            if(temp[i]>temp[i+1]){
                return false;
            }
        }
        return true;
    }
};