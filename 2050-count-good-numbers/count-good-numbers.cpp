class Solution {
    int mod=1e9+7;
    long long binaryexp(int x,long long n){
        int ret=1;
        int mul=x;
        while(n>0){
            if(n%2==1){
                ret=(long long)ret*mul%mod;
            }
            mul=(long long)mul*mul%mod;
            n/=2;
        }
        return ret;
    }
public:
    int countGoodNumbers(long long n) {
        return (binaryexp(5,(n+1)/2)*binaryexp(4,n/2))%mod;
    }
};