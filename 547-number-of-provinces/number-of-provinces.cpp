class Solution {
    void dfs(vector<vector<int>>&adj,vector<bool>&vis,int node){
        vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(adj,vis,it);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        int cnt=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(adj,vis,i);
            }
        }
        return cnt;
    }
};