class Solution {
public:
    int minOperations(int n) {
        int cnt=0, a, b;
        while(n) {
            cnt++;
            a = pow(2, ceil(log(n)/log(2)));
            b = pow(2, floor(log(n)/log(2)));
            if(a-n < n-b) n = a-n;
            else n = n-b;
        }
        return cnt;
    }
};