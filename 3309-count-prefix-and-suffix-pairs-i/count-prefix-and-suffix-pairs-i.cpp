class Solution {
    bool pair1(string &t,string &s){
        string tocheckreverse=s;
        reverse(tocheckreverse.begin(),tocheckreverse.end());
        int len=t.size();
        //cout<<s.substr(0,len)<<" "<<tocheckreverse.substr(0,len)<<endl;
        string w=tocheckreverse.substr(0,len);
        reverse(w.begin(),w.end());
        if(s.substr(0,len)==t&&w==t)return true;
        return false;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int ans=0;
        for(int i=0;i<n;i++){
            string tocheck=words[i];
            for(int j=i+1;j<n;j++){
                if(tocheck.size()>words[j].size())continue;
                if(pair1(tocheck,words[j])){
                    cout<<tocheck<<" "<<words[j]<<endl;
                    ans++;
                }
            }
        }
        return ans;
    }
};