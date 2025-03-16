class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> prev(n, -1), next(n, -1);
        unordered_map<int, int> lastPos;
        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;
            if (lastPos.find(nums[idx]) != lastPos.end()) {
                prev[idx] = lastPos[nums[idx]];
            }
            lastPos[nums[idx]] = idx;
        }

        lastPos.clear();
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;
            if (lastPos.find(nums[idx]) != lastPos.end()) {
                next[idx] = lastPos[nums[idx]];
            }
            lastPos[nums[idx]] = idx;
        }

        int m = queries.size();
        vector<int> ans(m, -1);
        for (int i = 0; i < m; i++) {
            int idx = queries[i];

            if (idx < 0 || idx >= n) continue; 
            int nextele = (next[idx] != -1) ? (next[idx] - idx + n) % n : INT_MAX;
            int prevele = (prev[idx] != -1) ? (idx - prev[idx] + n) % n : INT_MAX;

            if (nextele != INT_MAX || prevele != INT_MAX) {
                ans[i] = min(nextele, prevele);
                if(ans[i]==0){
                    ans[i]=-1;
                }
            }
        }

        return ans;
    }
};
