
class Solution {
    bool pred(vector<int>& ranks, int cars, long long mid) {
        long long k = 0;
        for (auto it : ranks) {
            k += sqrt(mid / it);
            if (k >= cars) return true; 
        }
        return k >= cars;
    }

public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1, high = 1e14;
        while (low < high) {
            long long mid = (low + high) / 2;
            if (pred(ranks, cars, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
