class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        int lastindex=INT_MAX;
        for(int i=0;i<mat.size();i++){
            int rowlast=0;
            for(int j=0;j<mat[0].size();j++){
                rowlast=max(rowlast,mp[mat[i][j]]);
            }
            //cout<<rowlast<<" ";
            lastindex=min(lastindex,rowlast);
        }
        for(int i=0;i<mat[0].size();i++){
            int collast=0;
            for(int j=0;j<mat.size();j++){
                collast=max(collast,mp[mat[j][i]]);
            }
            //cout<<collast<<" ";
            lastindex=min(lastindex,collast);
        }
        return lastindex;
    }
};