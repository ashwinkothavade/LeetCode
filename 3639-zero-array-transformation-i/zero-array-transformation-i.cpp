class Solution {
bool valid(vector<int>&nums,vector<int>&v){
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
        nums[i]+=sum;
        if(nums[i]>0)return false;
    }
    return true;
}
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>v(n+1,0);
        for(auto it:queries){
            int a=it[0];
            int b=it[1];
            v[a]--;
            if(b+1<n){
                v[b+1]++;
            }
            
        }
        return valid(nums,v);
    }
};