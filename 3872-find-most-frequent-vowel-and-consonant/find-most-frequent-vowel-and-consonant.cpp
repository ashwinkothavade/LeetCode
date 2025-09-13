class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<int,int>mp;
        unordered_set<char>st={'a','e','i','o','u'};
        int cnt1=0;
        int cnt2=0;
        for(auto it:s){
            mp[it]++;
            if(st.find(it)!=st.end()){
                cnt1=max(cnt1,mp[it]);
            }else{
                cnt2=max(cnt2,mp[it]);
            }
        }
        return cnt1+cnt2;
    }
};