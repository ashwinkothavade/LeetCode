class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int k=mp.size();
        // cout<<k<<endl;
        // int cnt=0;
        int i=0;
        int j=0;
        int ans=0;
        unordered_map<int,int>temp;
        while(i<n){
            temp[nums[i]]++;
            while(temp.size()==k&&j<n&&i>=j){
                // for(auto it:temp){
                //     cout<<it.first<<" "<<it.second<<endl;
                // }
                // cout<<endl;
                // // cout<<i<<endl;
                ans+=(n-i);
                // cout<<ans<<endl;
                temp[nums[j]]--;
                if(temp[nums[j]]==0){
                    temp.erase(nums[j]);
                }
                j++;
            }
            i++;
        }
        return ans;
    }
};