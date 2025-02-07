class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int minfre=INT_MAX;
        for(auto it:nums){
            mp[it]++;
        }
        int maxfre=0;
        for(auto it:mp){
            maxfre=max(maxfre,it.second);
        }
        return n-maxfre;

    }
};