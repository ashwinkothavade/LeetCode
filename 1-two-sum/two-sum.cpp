class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n=nums.size();
        //brute force
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]+nums[j]==target){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {-1,-1};
        //optimal solution
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int rem=target-nums[i];
            if(mp.find(rem)!=mp.end()){
                return {i,mp[rem]};
            }else{
                mp[nums[i]]=i;
            }
        }
        return {-1,-1};
    }
};