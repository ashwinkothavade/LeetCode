class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int tones=0;
        int tzeroes=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                tzeroes++;
            }else{
                tones++;
            }
        }
        int ones=0;
        int maxscore=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1'){
                ones++;
            }
            maxscore=max(maxscore,tones-ones+(i-ones+1));
        }
        return maxscore;
    }
};