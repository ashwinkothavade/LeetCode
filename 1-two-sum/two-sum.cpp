class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //brute force solution check all the possible pairs of the numbers and then compare their sum with the target once the sum is equal to the target then we can return the indices of the two numbers.here is the time complexity will be order of O(n^2) and the space complexity will be O(1) for this we need to optimize the time complexity 
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {-1,-1};

        //optimal 

    }
};