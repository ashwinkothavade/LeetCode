class Solution {
    int n;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& g, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || g[r1][c1] == -1 || g[r2][c2] == -1) 
            return -1e9;
        if (r1 == n-1 && c1 == n-1) 
            return g[r1][c1];
        if (dp[r1][c1][r2] != -1) 
            return dp[r1][c1][r2];

        int cherries = g[r1][c1];
        if (r1 != r2) cherries += g[r2][c2];

        int ans = max({solve(g, r1+1, c1, r2+1), 
                       solve(g, r1, c1+1, r2), 
                       solve(g, r1+1, c1, r2), 
                       solve(g, r1, c1+1, r2+1)});
        
        cherries += ans;
        return dp[r1][c1][r2] = cherries;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        dp.assign(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return max(0, solve(grid, 0, 0, 0));
    }
};
