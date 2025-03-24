class Solution {
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        if (n == 0) return ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            if (ans.back()[1] >= intervals[i][0]) {  
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>>merged=merge(meetings);
        int n=merged.size();
        int ans=0;
        if(merged[0][0]!=1){
            ans+=merged[0][0]-1;
        }
        for(int i=0;i<n-1;i++){
            ans+=merged[i+1][0]-merged[i][1]-1;
        }
        ans+=days-merged[n-1][1];
        return ans;
        
    }
};