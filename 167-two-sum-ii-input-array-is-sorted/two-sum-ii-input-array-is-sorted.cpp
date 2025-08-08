class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         int n=nums.size();
         int i=0;
         int j=n-1;
         while(j>i){
            if(nums[i]+nums[j]>target){
                j--;
            }else if(nums[i]+nums[j]<target){
                i++;
            }
            else if(nums[i]+nums[j]==target){
                return {i+1,j+1};
            }

            // cout<<i<<" "<<j<<endl;
         }
         return {-1,-1};
    }
};