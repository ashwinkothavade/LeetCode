class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>ans(n,0);
        int count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[A[i]]++;
            mp[B[i]]++;
            if(A[i]==B[i]){
                count++;
            }else{
                if(mp[A[i]]==2){
                    count++;
                }
                if(mp[B[i]]==2){
                    count++;
                }
            }
            ans[i]=count;
        }
        return ans;
    }
};