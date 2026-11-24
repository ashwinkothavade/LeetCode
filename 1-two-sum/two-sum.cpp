class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //brute force solution check all the possible pairs of the numbers and then compare their sum with the target once the sum is equal to the target then we can return the indices of the two numbers.here is the time complexity will be order of O(n^2) and the space complexity will be O(1) for this we need to optimize the time complexity 
        int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]+nums[j]==target){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {-1,-1};

        //optimal: in the brute force solution the problem is the time complexity of the level of n^2 we store the number along with the indices in the hashmap with number as the key and index as the value,when we iterate in the array we keep checking target-nums[i] in the map and if we find it then return that index and the current index of the array else we move ahead in the array until we find such index we match our condition

        unordered_map<int,int>mp;
        mp[nums[0]]=0;
        for(int i=1;i<n;i++){
            if(mp.find(target-nums[i])!=mp.end()){
                return {i,mp[target-nums[i]]};
            }else{
                mp[nums[i]]=i;
            }
            // for(auto it:mp){
            //     cout<<it.first<<" "<<it.second<<endl;
            // }
            // cout<<endl;
        }
        return {-1,-1};

    }
};