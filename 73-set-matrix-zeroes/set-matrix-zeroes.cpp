class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    v.push_back({i,j});
                }
            }
        }
        for(int i=0;i<v.size();i++){
            int t=v[i].first;
            int w=v[i].second;
            for(int j=0;j<m;j++){
                matrix[t][j]=0;
            }
            for(int j=0;j<n;j++){
                matrix[j][w]=0;
            }

        }


    }
};