class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int n=fruits.size();
        int i=0;
        int j=0;
        int maxcnt=0;
        while(i<n){
            mp[fruits[i]]++;
            while(mp.size()>2&&i>j&&j<n){
                mp[fruits[j]]--;
                if(mp[fruits[j]]==0){
                    mp.erase(fruits[j]);
                }
                j++;
            }
            int temp=0;
            for(auto it:mp){
                temp+=it.second;
            }
            // for(auto it:mp){
            //     cout<<it.first<<" "<<it.second<<endl;
            // }
            // cout<<endl;
            maxcnt=max(maxcnt,temp);
            // cout<<i<<" "<<maxcnt<<endl;
            // cout<<endl;
            i++;
        }
        return maxcnt;
    }
};