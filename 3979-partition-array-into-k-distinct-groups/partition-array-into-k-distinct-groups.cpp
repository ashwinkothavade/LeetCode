class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       for(auto it:nums){
        mp[it]++;
       }
       int numberofunique=mp.size();
       int n=nums.size();
       if(n%k!=0)return false;
       for(auto it:mp){
        if(it.second>n/k){
            return false;
        }
       }
       return true;
    }
};