class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int,int>mp;
        while(n>0){
            mp[n%10]++;
            n/=10;
        }
        int ans=INT_MAX;
        int minfreq=INT_MAX;
        for(auto it:mp){
            if(it.second<minfreq){
                minfreq=it.second;
                ans=it.first;
            }else if(it.second==minfreq){
                ans=min(ans,it.first);
            }
        }
        return ans;
    }
};