class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        for (int k = 0; k < 3; k++) {
            dp[0][0][k] = (coins[0][0] < 0 && k > 0) ? 0 : coins[0][0];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    if (i == 0 && j == 0) continue;
                    int gain = coins[i][j];
                    if (i > 0) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + gain);
                        if (k > 0 && gain < 0) {
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
                        }
                    }
                    if (j > 0) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + gain);
                        if (k > 0 && gain < 0) {
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1]);
                        }
                    }
                }
            }
        }
        return max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
    }
};
