class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int j=0;
        unordered_map<int,int>mp;
        int maxlen=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp[s[i]]!=1&&i>j){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    mp.erase(s[j]);
                }
                j++;
            }
            maxlen=max(maxlen,i-j+1);
        }
        return maxlen;
    }
};