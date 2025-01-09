class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int len=pref.size();
        int ans=0;
        for(int i=0;i<n;i++){
            string t=words[i].substr(0,len);
            if(t==pref)ans++;
        }
        return ans;
    }
};