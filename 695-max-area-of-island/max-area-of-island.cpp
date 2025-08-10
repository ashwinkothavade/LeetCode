class Solution {
private:
    void bfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, int &n, int &m, vector<int> &ans){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        int totalCnt = 0;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            totalCnt++;
            
            for(int k = 0; k < 4; ++k){
                int nrow = row + dr[k];
                int ncol = col + dc[k];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        
        ans.push_back(totalCnt);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> ans;
        
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    bfs(i, j, grid, vis, n, m, ans);
                }
            }
        }
        if(ans.empty()) return 0;
        
        return *max_element(ans.begin(), ans.end());
    }
};