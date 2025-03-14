class Solution {
public:
    bool valid_bin_sea(vector<int>& candies, long long k, long long search){
        long long ans = 0;
        if(!search) return false;
        int n = candies.size();
        if(search > 1e7) search = 1e7+1;
        for(int i = 0;i < n; i++){
            ans += candies[i]/search;
        }
        return ans >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int ans = 0;
        long long low = 0, hi = 1e18;
        long long mid = low + (hi-low)/2;
        while(low < hi){
            mid = low + (hi-low)/2;
            if(valid_bin_sea(candies,k,mid)){
                ans = mid;
                low = mid+1;
            }else{
                hi = mid;
            }
        }
        mid = low + (hi-low)/2;
        return ans;
    }
};