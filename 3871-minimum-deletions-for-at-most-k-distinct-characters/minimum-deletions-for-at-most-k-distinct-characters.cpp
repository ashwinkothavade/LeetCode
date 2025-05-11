class Solution {
public:
    int minDeletion(string s, int k) {
        map<char,int>mp;
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<char,int>>>pq;
        for(auto ch:s){
            mp[ch]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        int t=mp.size();
        int temp=mp.size()-k;
        int ans=0;
        while(temp>0){
            ans+=pq.top().first;
            pq.pop();
            temp--;
        }
        return ans;
    }
};