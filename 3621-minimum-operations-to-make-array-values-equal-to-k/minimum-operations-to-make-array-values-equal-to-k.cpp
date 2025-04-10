class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        if(nums[n-1]==k)return st.size()-1;
        else if(nums[n-1]!=k&&k<nums[n-1])return st.size();
        return -1;
        
    }
};