class Solution {
    bool cnt(int num){
        int c=0;
        while(num>0){
            c++;
            num/=10;
        }
        return c%2==0;
    }
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(auto it:nums){
            if(cnt(it)){
                ans++;
            }
        }
        return ans;
    }
};