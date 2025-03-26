class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>g;
        int t=grid[0][0]%x;
        for(auto it:grid){
            for(auto i:it){
                if(i%x==t)
                g.push_back(i);
                else{
                    return -1;
                }
            }
        }
        int ans=0;
        sort(g.begin(),g.end());
        int med=g[g.size()/2];
        for(auto it:g){
            ans+=abs((it-med)/x);
        }
        return ans;
    }
};