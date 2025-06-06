class Solution {
public:
    int alternatingSubarray(vector<int>& v) {
        int ans = 0;
        for(int i = 0; i < v.size() - 1; i += 1) {
            bool flag = true;
            int cnt = 1;
            for(int j = i + 1; j < v.size(); j += 1) {
                if(v[j] - v[j - 1] != (flag ? 1 : -1)) break;
                flag = !flag;
                cnt += 1;
            }
            ans = max(ans, cnt);
        }
        return ans <= 1 ? -1 : ans;
    }
};