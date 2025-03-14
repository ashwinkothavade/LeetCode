
class Solution {
    bool pred(vector<int>& candies, long long k, long long mid) {
        long long count = 0;
        for (int candy : candies) {
            count += candy / mid; 
        }
        return count >= k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1; 
        long long high = *max_element(candies.begin(), candies.end());
        
        while (low <= high) {
            long long mid = low + (high - low) / 2; 
            if (pred(candies, k, mid)) {
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }
        return high; 
    }
};
