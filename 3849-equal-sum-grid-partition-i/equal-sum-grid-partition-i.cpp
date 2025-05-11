class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long totalsum = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                totalsum += grid[i][j];
            }
        }

        long long tempsum = 0;
        for (int i = 0; i < n - 1; i++) { 
            for (int j = 0; j < m; j++) {
                tempsum += grid[i][j];
            }
            long long rem = totalsum - tempsum;
            if (rem == tempsum && rem && tempsum) {
                return true;
            }
        }

        tempsum = 0;
        for (int i = 0; i < m - 1; i++) { 
            for (int j = 0; j < n; j++) {
                tempsum += grid[j][i];
            }
            long long rem = totalsum - tempsum;
            if (rem == tempsum && rem && tempsum) {
                return true;
            }
        }

        return false;
    }
};
