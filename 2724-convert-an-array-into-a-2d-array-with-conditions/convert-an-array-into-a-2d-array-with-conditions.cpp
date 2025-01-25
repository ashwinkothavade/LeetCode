class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        vector<vector<int>> ans;

        while (!mp.empty()) {
            vector<int> temp;
            vector<int> toRemove;

            for (auto& [key, count] : mp) {
                temp.push_back(key);
                mp[key]--;
                if (mp[key] == 0) {
                    toRemove.push_back(key);
                }
            }

            for (int key : toRemove) {
                mp.erase(key);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
