class Solution {
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};

    int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, int n, int m) {
        queue<pair<int, int>> p;
        p.push({i, j});
        vis[i][j] = 1;
        int sum = 0;

        while (!p.empty()) {
            int row = p.front().first;
            int col = p.front().second;
            sum += grid[row][col];
            p.pop();

            for (int k = 0; k < 4; k++) {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] != 0) {
                    vis[nrow][ncol] = 1;
                    p.push({nrow, ncol});
                }
            }
        }

        return sum;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0 && vis[i][j] == 0) {
                    ans = max(ans, bfs(grid, vis, i, j, n, m));
                }
            }
        }

        return ans;
    }
};
