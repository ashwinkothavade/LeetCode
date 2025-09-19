class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int maxi=0;
        int t=tasks.size();
        for(auto it:tasks){
            mp[it]++;
            maxi=max(maxi,mp[it]);
        }
        int cnt=0;
        for(auto it:mp){
            if(it.second==maxi){
                cnt++;
            }
        }
        return max(t,(n+1)*(maxi-1)+cnt);
    }
};