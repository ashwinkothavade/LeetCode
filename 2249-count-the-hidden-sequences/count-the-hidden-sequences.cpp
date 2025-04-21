class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n=differences.size();
        int cnt=upper-lower+1;
        int low=lower;
        int up=upper;
        for(int i=0;i<n;i++){
            low=max(lower,low+differences[i]);
            up=min(upper,up+differences[i]);
            cnt=max(0,min(cnt,up-low+1));
            if(cnt==0)return 0;
        }
        return cnt;
    }
};