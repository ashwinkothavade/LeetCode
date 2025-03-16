class Solution {
    bool check(vector<int>& nums, vector<unordered_set<int>>& mp) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            if (mp[i].find(nums[i]) == mp[i].end()) {
                return false;
            }
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<unordered_set<int>> mp(n);
        int m = queries.size();
        if(check(nums,mp))return 0;
        for (int i = 0; i < m; i++) {
            auto it = queries[i];
            for (int j = it[0]; j <= it[1]; j++) {
                unordered_set<int> temp = mp[j]; 
                for (auto w : temp) { 
                    mp[j].insert(w + it[2]);
                }
                mp[j].insert(it[2]);
            }
            if (check(nums, mp)) {
                return i + 1;
            }
        }
        return -1;
    }
};
