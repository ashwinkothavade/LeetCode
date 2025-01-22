class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(isWater[i][j]==1){
                    vis[i][j]=1;
                    pq.push({0,{i,j}});
                }
            }
        }
        vector<vector<int>>ans(n,vector<int>(m,0));
        int delrow[4]={0,1,0,-1};
        int delcol[4]={1,0,-1,0};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int cost=it.first;
            int row=it.second.first;
            int col=it.second.second;
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0&&ncol>=0&&ncol<m&&nrow<n&&!vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    pq.push({cost+1,{nrow,ncol}});
                    ans[nrow][ncol]=cost+1;
                }
            }
        }
        return ans;
    }
};