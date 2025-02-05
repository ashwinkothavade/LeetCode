class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n - k + 1, 0);

        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> mp;
            int sum = 0;
            
            for (int j = i; j < i + k; j++) {
                mp[nums[j]]++;
                sum += nums[j];
            }

            if (mp.size() < x) {
                ans[i] = sum;
            } else {
                // Min-heap for top x frequent elements
                priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

                for (auto it : mp) {
                    pq.push({it.second, it.first});
                    if (pq.size() > x) {
                        pq.pop();
                    }
                }

                int sum1 = 0;
                while (!pq.empty()) {
                    auto top = pq.top();
                    pq.pop();
                    sum1 += top.second*top.first; // Use element value, not frequency
                }
                ans[i] = sum1;
            }
        }
        return ans;
    }
};
