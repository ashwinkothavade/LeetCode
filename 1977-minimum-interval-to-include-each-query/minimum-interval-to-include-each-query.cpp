class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Sort intervals by start
        sort(intervals.begin(), intervals.end());
        // Store original queries with index
        vector<pair<int,int>> q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end()); // sort queries by value

        vector<int> ans(queries.size(), -1);
        // Min-heap storing {interval length, interval end}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int j=0, n=intervals.size();
        for(int i=0;i<q.size();i++){
            int query = q[i].first;

            // Add intervals whose start <= query
            while(j<n && intervals[j][0] <= query){
                int l = intervals[j][0], r = intervals[j][1];
                pq.push({r-l+1, r});
                j++;
            }

            // Remove intervals whose end < query
            while(!pq.empty() && pq.top().second < query){
                pq.pop();
            }

            // Answer for this query
            if(!pq.empty()){
                ans[q[i].second] = pq.top().first;
            }
        }
        return ans;
    }
};
