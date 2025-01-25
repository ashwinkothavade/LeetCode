class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        map<int, queue<int>> l; 
        unordered_map<int, int> lmp; 
        vector<int> sor(nums.begin(), nums.end());
        sort(sor.begin(), sor.end());
        int curr = 0;
        l[curr].push(sor[0]);
        lmp[sor[0]] = curr;
        for (int i = 1; i < sor.size(); i++) {
            if (sor[i] - l[curr].back() <= limit) {
                l[curr].push(sor[i]);
            } else {
                curr++;
                l[curr].push(sor[i]);
            }
            lmp[sor[i]] = curr; 
        }
        for (int i = 0; i < nums.size(); i++) {
            int ele = lmp[nums[i]]; 
            nums[i] = l[ele].front(); 
            l[ele].pop();
        }
        return nums;
    }
};