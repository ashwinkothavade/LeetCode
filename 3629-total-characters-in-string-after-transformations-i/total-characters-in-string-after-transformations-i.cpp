class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(26, vector<long long>(t + 1, 0));

        for (char ch : s) {
            dp[ch - 'a'][0]++;
        }

        for (int i = 1; i <= t; i++) {
            for (int c = 0; c < 26; c++) {
                if (c == 25) { 
                    dp[0][i] = (dp[0][i] + dp[25][i - 1]) % MOD;
                    dp[1][i] = (dp[1][i] + dp[25][i - 1]) % MOD; 
                } else {
                    dp[c + 1][i] = (dp[c + 1][i] + dp[c][i - 1]) % MOD;
                }
            }
        }
        long long ans = 0;
        for (int c = 0; c < 26; c++) {
            ans = (ans + dp[c][t]) % MOD;
        }

        return ans;
    }
};
