class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        unordered_map<int,string>mp1;
        string ans="";
        int freq=0;
        for(auto it:mp){
            mp1[it.second].push_back(it.first);
            if(mp1[it.second].size()>ans.size()){
                ans=mp1[it.second];
                freq=it.second;
            }else if(mp1[it.second].size()==ans.size()){
                if(it.second>freq){
                    ans=mp1[it.second];
                    freq=it.second;
                }
            }
        }
        return ans;
    }
};