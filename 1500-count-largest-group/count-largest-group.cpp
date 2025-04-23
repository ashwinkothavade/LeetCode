class Solution {
    int digitsum(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        int maxele=INT_MIN;
        for(int i=1;i<=n;i++){
            mp[digitsum(i)]++;
            maxele=max(maxele,mp[digitsum(i)]);
        }
        int ans=0;
        for(auto it :mp){
            if(it.second==maxele){
                ans++;
            }
        }
        return ans;
    }
};