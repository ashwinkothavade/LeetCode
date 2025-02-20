class Solution {
    string solve(string s, set<string>& st, int ind, int n) {
        if (s.size() == n) {
            if (st.find(s) == st.end()) {
                return s;
            }
            return ""; 
        }
        for (char c : {'0', '1'}) {
            s.push_back(c);
            string res = solve(s, st, ind + 1, n);
            if (!res.empty()) return res; 
            s.pop_back();
        }
        return ""; 
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> st(nums.begin(), nums.end());
        return solve("", st, 0, nums.size());
    }
};
