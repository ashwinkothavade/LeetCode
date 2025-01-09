class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string t;
        int n=words.size();
        for(int i=0;i<n;i++){
            t+=words[i];
            if(t==s)return true;
        }
        return false;
    }
};