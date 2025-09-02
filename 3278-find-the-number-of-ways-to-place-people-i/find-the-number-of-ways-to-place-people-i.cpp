class Solution {
    bool valid(vector<int>& a, vector<int>& b, vector<vector<int>>& points, int indexa, int indexb) {
        int n = points.size();
        if (!(a[0] <= b[0] && a[1] >= b[1])) {
            return false;
        }
        if (n == 2) return true;
        for (int k = 0; k < n; k++) {
            if (k == indexa || k == indexb) continue;
            auto& pointTmp = points[k];
            bool isXContained = (pointTmp[0] >= a[0] && pointTmp[0] <= b[0]);
            bool isYContained = (pointTmp[1] <= a[1] && pointTmp[1] >= b[1]);
            if (isXContained && isYContained) {
                return false;
            }
        }
        return true;
    }

public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (valid(points[i], points[j], points, i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
