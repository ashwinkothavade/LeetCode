class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> str2=strs;
        int n=strs.size();
        for(int i=0;i<n;i++){
            sort(str2[i].begin(),str2[i].end());
        }
        // for(auto it:str2){
        //     cout<<it<<endl;
        // }
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<n;i++){
            if(mp.find(str2[i])!=mp.end()){
                mp[str2[i]].push_back(strs[i]);
            }else{
                mp[str2[i]].push_back(strs[i]);
            }
        }
        vector<vector<string>>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
        return {};

    }
};