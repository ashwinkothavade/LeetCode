class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        set<string>ans;
        for(int i=0;i<n;i++){
            string tocheck=words[i];
            for(int j=0;j<n;j++){
                if(i!=j){
                    for(int k=0;k<words[j].size();k++){
                        string t=words[j].substr(k,tocheck.size());
                        if(t==tocheck){
                            ans.insert(t);
                        }
                    }
                }
            }
        }
        vector<string>temp;
        for(auto it:ans){
            temp.push_back(it);
        }
        return temp;
    }
};