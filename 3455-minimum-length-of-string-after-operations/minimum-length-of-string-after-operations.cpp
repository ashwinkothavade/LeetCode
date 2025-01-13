class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        unordered_map<char,int>mp1;
        int len=n;
        for(int i=0;i<n;i++){
            mp1[s[i]]++;
        }
        for(auto it:mp1){
            len-=((it.second-1)/2)*2;
        }
        return len;
         
    }
};