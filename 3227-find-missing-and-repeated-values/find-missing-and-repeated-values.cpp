class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>mp(n*n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[grid[i][j]]++;
            }
        }
        int a,b;
        for(int i=1;i<=n*n;i++){
            if(mp[i]==2){
                a=i;
            }else if(mp[i]==0){
                b=i;
            }
        }
        return {a,b};
    }
};