class Solution {
    bool condition(string &s){
        int n=s.size();
        set<char>st={'a','e','i','o','u'};
        if(st.find(s[0])!=st.end()&&st.find(s[n-1])!=st.end()){
            return true;
        }
        return false;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<bool>count(n,0);
        for(int i=0;i<n;i++){
            count[i]=condition(words[i]);
        }
        vector<int>prefix(n,0);
        prefix[0]=count[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+count[i];
        }
        int m=queries.size();
        vector<int>ans(m,0);
        for(int i=0;i<m;i++){
            int a=queries[i][0];
            int b=queries[i][1];
            ans[i]=prefix[b]-prefix[a]+count[a];
        }
        return ans;

    }
};