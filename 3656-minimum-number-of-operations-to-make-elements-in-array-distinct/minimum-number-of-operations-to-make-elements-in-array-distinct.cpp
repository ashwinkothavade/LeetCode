class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        if(mp.size()==n){
            return 0;
        }
        int ans=0;
        for(int i=0;i<n;i+=3){
            for(int j=i;j<i+3&&j<n;j++){
                mp[nums[j]]--;
                if(mp[nums[j]]==0)mp.erase(nums[j]);
            }
            ans++;
            if(mp.size()==n-3*ans)return ans;
        }
        return ans;
    }
};