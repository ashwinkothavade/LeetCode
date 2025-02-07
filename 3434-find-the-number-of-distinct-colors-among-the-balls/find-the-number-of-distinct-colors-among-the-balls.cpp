class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int>v;
        unordered_map<int,int>mp;
        unordered_map<int,int>cf;
        int dc=0;
        for(int i=0;i<n;i++){
            unordered_set<int>balls;
            int x=queries[i][0];
            int y=queries[i][1];
            if(mp.count(x)){
                int oc=mp[x];
                cf[oc]--;
                if(cf[oc]==0){
                    dc--;
                    cf.erase(oc);
                }
            }
            mp[x]=y;
            cf[y]++;
            if(cf[y]==1){
                dc++;
            }
            v.push_back(dc);

        }
        return v;

        
    }
};