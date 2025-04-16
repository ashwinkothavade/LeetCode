class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int, int> mp;
        int l = 0;
        int n = nums.size();
        long long currpairs = 0;

        for (int r = 0; r < n; r++) {
            currpairs += mp[nums[r]];
            mp[nums[r]]++;
            while (currpairs >= k) {
                ans += n - r; 
                currpairs -= (mp[nums[l]] - 1); 
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                l++;
            }
        }
        return ans;
    }
};
