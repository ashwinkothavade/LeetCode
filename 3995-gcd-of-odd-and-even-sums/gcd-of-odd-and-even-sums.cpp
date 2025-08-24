class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int evensum=n*(n+1);
        int oddsum=n*n;
        return __gcd(oddsum,evensum);
    }
};