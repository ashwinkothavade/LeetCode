class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<int>ans;
        for(auto it:mp){
            if(it.second>k){
                for(int i=0;i<k;i++){
                    ans.push_back(it.first);
                }
            }else{
                for(int i=0;i<it.second;i++){
                    ans.push_back(it.first);
                }
            }
        }
        return ans;
    }
};