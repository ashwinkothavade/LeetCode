class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mp;
        for(auto c:s){
            mp[c]++;
        }
        int maxodd=0;
        int mineve=INT_MAX;
        for(auto it:mp){
            if(it.second%2==1){
                if(it.second>maxodd){
                    maxodd=it.second;
                }
            }else if(it.second%2==0){
                if(it.second<mineve){
                    mineve=it.second;
                }
            }
        }
        return maxodd-mineve;
    }
};