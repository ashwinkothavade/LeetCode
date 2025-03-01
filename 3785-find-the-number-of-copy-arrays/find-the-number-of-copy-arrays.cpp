class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bound) {
        int n=original.size();
        int lower=bound[0][0];
        int upper=bound[0][1];
        int ans=upper-lower+1;
        for(int i=1;i<n;i++){
            int diff=original[i]-original[i-1];
            lower=max(lower+diff,bound[i][0]);
            upper=min(upper+diff,bound[i][1]);
            ans=min(ans,upper-lower+1);
            if(ans<0){
                return 0;
            }
        }
        return ans;
    }
};