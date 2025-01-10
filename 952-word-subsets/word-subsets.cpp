class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>temp(26,0);
        vector<int>final(26,0);
        for(auto it:words2){
            for(int i=0;i<26;i++){
                temp[i]=0;
            }
            for(auto c:it){
                temp[c-'a']++;
            }
            for(int i=0;i<26;i++){
                final[i]=max(final[i],temp[i]);
            }
        }
        unordered_map<char,int>mp;
        for(int i=0;i<26;i++){
            if(final[i])
            mp[i+'a']=final[i];
        }
        
        vector<string>ans;
        for(auto it:words1){
            unordered_map<char,int>temp;
            for(auto c:it){
                temp[c]++;
            }
            bool flag=true;
            for(auto check:mp){
                if(temp.find(check.first)==temp.end()){
                    flag=false;
                }else{
                    if(temp[check.first]<check.second){
                        flag=false;
                    }
                }
            }
            if(flag){
                ans.push_back(it);
            }
        }
        return ans;
    }
};