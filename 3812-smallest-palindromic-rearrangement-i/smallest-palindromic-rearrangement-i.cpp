class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int>mp;
        for(auto ch:s){
            mp[ch]++;
        }
        int oddc=0;
        char oddch;
        for(auto it:mp){
            if(it.second%2==1){
                oddc++;
                oddch=it.first;
            }
        }
        string half="";
        if(oddc>1)return "";
        for(auto it:mp){
            half+=string(it.second/2,it.first);
        }
        
        string rev=half;
        if(oddc==1)half+=oddch;
        reverse(rev.begin(),rev.end());
        half+=rev;
        return half;
    }
};