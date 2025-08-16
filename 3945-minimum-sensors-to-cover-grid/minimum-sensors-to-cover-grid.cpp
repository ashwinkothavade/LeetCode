class Solution {
public:
    int minSensors(int n, int m, int k) {
        k = 2*k +1;
        return ((n+k-1)/k) * ((m+k-1)/k);
    }
};