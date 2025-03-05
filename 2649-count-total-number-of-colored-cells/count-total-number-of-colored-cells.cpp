class Solution {
public:
    long long coloredCells(int n) {
        long long ans=1;
        int count=0;
        while(n--){
            ans+=4*count;
            count++;
        }
        return ans;
    }
};