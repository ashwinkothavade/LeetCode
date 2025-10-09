class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

        for (int j = 1; j <= m; j++) {
            for (int i = 1; i <= n; i++) {
                dp[j][i] = dp[j][i - 1] + (long long)skill[i - 1] * mana[j - 1];
            }
            long long plus = 0;
            for (int i = 1; i <= n; i++) {
                plus = max(plus, dp[j - 1][i] - dp[j][i - 1]);
            }
            for (int i = 1; i <= n; i++) {
                dp[j][i] += plus;
            }
        }
        return dp[m][n];
    }
};