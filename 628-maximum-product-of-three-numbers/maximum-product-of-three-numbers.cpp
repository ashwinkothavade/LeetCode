class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int product=1;
        int n=nums.size();
        product*=nums[n-1]*nums[n-2]*nums[n-3];
        int product2=1;
        product2*=nums[0]*nums[1]*nums[n-1];
        return max(product,product2);  
    }
};