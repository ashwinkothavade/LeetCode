class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n = groups.size(), m = elements.size();
        vector<int> ans(n, -1);
        unordered_map<int,int>mp2;
        for(int i=0;i<m;i++){
            if(mp2.find(elements[i])==mp2.end()){
                mp2[elements[i]]=i;
            }
        }
        // for(auto it:mp2){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        for (int i = 0; i < n; i++) {
            int minind=INT_MAX;
            for (int j = 1; j * j <= groups[i]; j++) {
                if (groups[i] % j == 0) {
                    if(mp2.find(j)!=mp2.end()){
                        minind=min(minind,mp2[j]);
                    }
                    if (j != groups[i] / j) {
                        if(mp2.find(groups[i]/j)!=mp2.end()){
                            minind = min(minind, mp2[groups[i] / j]);
                        }
                    }
                }
            }
            if(minind!=INT_MAX){
                ans[i]=minind;
            }
        }
        return ans;
    }
};