class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd=n+(n*(n-1));
        int sumeven=2*n+(n*(n-1));
        return __gcd(sumodd,sumeven);
    }
};