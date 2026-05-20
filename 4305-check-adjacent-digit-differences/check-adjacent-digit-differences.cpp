class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n=s.size();
        for(int i=0;i<n-1;i++){
            if(abs(((int)s[i]-(int)s[i+1]))>2){
                return false;
            }
        }
        return true;
    }
};