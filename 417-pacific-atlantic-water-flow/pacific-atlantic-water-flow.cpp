class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    void DFS(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&vis){
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            i=q.front().first;
            j=q.front().second;
            q.pop();
            vis[i][j]=true;
            for(int k=0;k<4;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx>=0&&ny>=0&&nx<grid.size()&&ny<grid[0].size()&&vis[nx][ny]==false&&grid[nx][ny]>=grid[i][j]){
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>v;
        int r=heights.size();
        int c=heights[0].size();
        vector<vector<bool>>vis1(r,vector<bool>(c,false));
        vector<vector<bool>>vis2(r,vector<bool>(c,false));
        for(int i=0;i<r;i++){
            DFS(heights,i,0,vis1);
        }
        for(int i=0;i<c;i++){
            DFS(heights,0,i,vis1);
        }
        for(int i=0;i<r;i++){
            DFS(heights,i,c-1,vis2);
        }
        for(int i=0;i<c;i++){
            DFS(heights,r-1,i,vis2);
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(vis1[i][j]==true&&vis2[i][j]==true){
                    v.push_back({i,j});
                }
            }
        }
        return v;
    }
};