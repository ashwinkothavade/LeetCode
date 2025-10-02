class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q; // {{row,col},time}
        
        // push all initially rotten oranges
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        
        int mtim = 0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        
        while(!q.empty()){
            auto it = q.front(); q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int tm = it.second;
            mtim = max(mtim, tm);
            
            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    q.push({{nrow,ncol}, tm+1});
                }
            }
        }
        
        // check if any fresh oranges remain
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return mtim;
    }
};
