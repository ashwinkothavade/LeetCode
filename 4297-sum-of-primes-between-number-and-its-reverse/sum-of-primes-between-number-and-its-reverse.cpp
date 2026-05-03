class Solution {
    vector<bool> sieve(int limit) {
        vector<bool> primes(limit + 1, true);
        primes[0] = primes[1] = false;
        for (int i = 2; i * i <= limit; i++) {
            if (primes[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    primes[j] = false;
                }
            }
        }
        return primes;
    }
    
public:
    int sumOfPrimesInRange(int n) {
        string s = to_string(n);
        string r = s;
        reverse(r.begin(), r.end());
        int r1 = stoi(r);
        
        int mini = min(n, r1);
        int maxi = max(n, r1);
        
        vector<bool> primes = sieve(maxi);
        int ans = 0;
        
        for (int i = mini; i <= maxi; i++) {
            if (primes[i]) {
                ans += i;
            }
        }
        return ans;
    }
};