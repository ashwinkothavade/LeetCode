class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char>st={'a','e','i','o','u'};
        int cnt1=0;
        for(auto it:s){
            if(st.find(it)!=st.end()){
                cnt1++;
            }
        }
        if(cnt1==0)return false;
        if(cnt1%2==1)return true;
        return true;
    }
};