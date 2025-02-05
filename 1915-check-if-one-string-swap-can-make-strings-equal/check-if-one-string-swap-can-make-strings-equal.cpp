class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(n!=m)return false;
        int first=0;
        int second=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                cnt++;
            }
            if(cnt==1&&s1[i]!=s2[i]){
                first=i;
            }
            if(cnt==2&&s1[i]!=s2[i]){
                second=i;
            }
            if(cnt>2){
                return false;
            }
        }
        cout<<first<<" "<<second;
        if(cnt==0)return true;
        if(cnt==1)return false;
        return s1[first]==s2[second]&&s1[second]==s2[first];
    }
};