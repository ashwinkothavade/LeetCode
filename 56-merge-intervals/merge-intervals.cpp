class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        int t=0;
        for(int i=1;i<n;i++){
            if(ans[t][1]>=intervals[i][0]){
                ans[t][1]=max(intervals[i][1],ans[t][1]);
            }else{
                ans.push_back(intervals[i]);
                t++;
            }
        }
        return ans;
    }
};