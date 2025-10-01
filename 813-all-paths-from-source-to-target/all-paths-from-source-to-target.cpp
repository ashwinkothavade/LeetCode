class Solution {
public:
    void dfs(vector<vector<int>>& a1,int src,vector<vector<int>>& ans,vector<int>& cur,vector<int>& vis){
        if(src==a1.size()-1){
            ans.push_back(cur);
            return;
        }
        for(auto it: a1[src]){
            if(!vis[it]){
                vis[it]=1;
                cur.push_back(it);
                dfs(a1,it,ans,cur,vis);
                cur.pop_back();
                vis[it]=0;
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& a1) {
        vector<int> vis(a1.size(),0);
        vis[0]=1;
        vector<vector<int>> ans;
        vector<int> cur;
        cur.push_back(0);
        dfs(a1,0,ans,cur,vis);
        return ans;
    }
};