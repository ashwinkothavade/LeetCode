class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(s[i]!=s[i+1]){
                ans++;
            }
        }
        if(s[0]=='1'){
            ans++;
        }
        return ans;
    }
};