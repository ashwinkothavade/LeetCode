#define ll pair<int,pair<int,int>>
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int cost = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if (cost > dist[row][col]) continue; // skip outdated entry
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                    int newCost = max(cost, moveTime[nrow][ncol]) + 1;
                    if (newCost < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newCost;
                        pq.push({newCost, {nrow, ncol}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
