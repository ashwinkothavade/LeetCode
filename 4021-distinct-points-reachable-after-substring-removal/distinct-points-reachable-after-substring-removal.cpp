class Solution {
public:
    int distinctPoints(string s, int k) {
        int x=0;
        int y=0;
        int n=s.size();
        for(auto it:s){
            if(it=='L'){
                x--;
            }else if(it=='R'){
                x++;
            }else if(it=='U'){
                y++;
            }else{
                y--;
            }
        }
        set<pair<int,int>>st;
        // int j=0;
        for(int i=0;i<k;i++){
            if(s[i]=='L'){
                x++;
            }else if(s[i]=='R'){
                x--;
            }else if(s[i]=='U'){
                y--;
            }else{
                y++;
            }
        }
        st.insert({x,y});
        int j=0;
        for(int i=k;i<n;i++){
            if(s[i]=='L'){
                x++;
            }else if(s[i]=='R'){
                x--;
            }else if(s[i]=='U'){
                y--;
            }else{
                y++;
            }
            if(s[j]=='L'){
                x--;
            }else if(s[j]=='R'){
                x++;
            }else if(s[j]=='U'){
                y++;
            }else{
                y--;
            }
            j++;
            st.insert({x,y});
        }
        return st.size();
    }
};