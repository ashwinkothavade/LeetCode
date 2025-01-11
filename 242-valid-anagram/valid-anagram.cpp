class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        if(s.size()!=t.size())return false;
        for(char c:s){
            mp[c]++;
        }
        for(auto z:t){
            if(mp.find(z)!=mp.end()){
                mp[z]--;
                if(mp[z]==0){
                    mp.erase(z);
                }
            }else{
                return false;
            }
        }
        return true;
    }
};