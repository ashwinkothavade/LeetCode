class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> mcost(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0}); // {cost, row, col}
        mcost[0][0] = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int cost = it[0];
            int row = it[1];
            int col = it[2];
            if (cost > mcost[row][col]) continue; 
            for (int i = 0; i < 4; i++) {
                int nrow = row + dir[i][0];
                int ncol = col + dir[i][1];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) { 
                    int newcost = cost + (i != (grid[row][col] - 1) ? 1 : 0);
                    if (mcost[nrow][ncol] > newcost) {
                        mcost[nrow][ncol] = newcost;
                        pq.push({newcost, nrow, ncol});
                    }
                }
            }
        }
        return mcost[n - 1][m - 1];
    }
};
