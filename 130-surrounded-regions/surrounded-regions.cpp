class Solution {
    void bfs(vector<vector<char>>&board,vector<vector<bool>>&vis,int i,int j){
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow<n&&nrow>=0&&ncol<m&&ncol>=0&&!vis[nrow][ncol]&&board[nrow][ncol]=='O'){
                    vis[nrow][ncol]=true;
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'&&!vis[0][i]){
                bfs(board,vis,0,i);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'&&!vis[i][0]){
                bfs(board,vis,i,0);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(board[i][m-1]=='O'&&!vis[i][m-1]){
                bfs(board,vis,i,m-1);
            }
        }
        for(int i=m-1;i>=0;i--){
            if(board[n-1][i]=='O'&&!vis[n-1][i]){
                bfs(board,vis,n-1,i);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'&&!vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};