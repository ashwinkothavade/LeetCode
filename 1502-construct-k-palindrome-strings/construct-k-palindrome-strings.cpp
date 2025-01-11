class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(auto c:s){
            mp[c]++;
        }
        int even=0;
        int odd=0;
        for(auto it:mp){
            if(it.second%2==0){
                even++;
            }else{
                odd++;
            }
        }
        int minstrings=odd;
        int maxstrings=n;
        return k>=minstrings && k<=maxstrings;
    }
};