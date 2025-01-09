class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans=0;
        int n=words.size();
        for(int i=0;i<n;i++){
            string t=s.substr(0,words[i].size());
            if(t==words[i])ans++;
        }
        return ans;
    }
};