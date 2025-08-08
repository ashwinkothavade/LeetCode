class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        set<int> st(nums.begin(), nums.end());
        int maxcnt = 0;

        for (int num : st) {
            if (st.find(num - 1) == st.end()) {
                int curr = num;
                int cnt = 1;

                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    cnt++;
                }
                maxcnt = max(maxcnt, cnt);
            }
        }
        return maxcnt;
    }
};
