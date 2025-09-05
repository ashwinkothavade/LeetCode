class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int maxtime=0;
        while(!q.empty()){
            auto it=q.front();
            int row=it.first.first;
            int col=it.first.second;
            int tm=it.second;
            q.pop();
            maxtime=max(tm,maxtime);
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow<n&&nrow>=0&&ncol<m&&ncol>=0&&!vis[nrow][ncol]&&grid[nrow][ncol]==1){
                    vis[nrow][ncol]=true;
                    q.push({{nrow,ncol},tm+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]==1){
                    return -1;
                }
            }
        }
        return maxtime;

    }
};