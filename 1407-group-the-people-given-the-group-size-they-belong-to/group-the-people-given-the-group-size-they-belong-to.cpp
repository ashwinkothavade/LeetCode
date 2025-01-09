class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        // for(auto it:mp){
        //     cout<<it.first<<endl;
        //     for(auto i:it.second){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        for(auto it:mp){
            int size1=it.first;
            int groups=it.second.size()/size1;
            for(int i=0;i<it.second.size();i+=it.first){
                vector<int>temp;
                for(int j=i;j<i+it.first;j++){
                    temp.push_back(it.second[j]);
                }
                ans.push_back(temp);
            }

        }
        return ans;
    }
};