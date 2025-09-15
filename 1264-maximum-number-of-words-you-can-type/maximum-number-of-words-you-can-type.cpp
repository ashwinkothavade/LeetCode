class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char>st(brokenLetters.begin(),brokenLetters.end());
        // vector <string> tokens;
        stringstream check1(text);
        string intermediate;
        int cnt=0;
        int n=0;
        while(getline(check1, intermediate, ' '))
        {
            for(auto it:intermediate){
                if(st.find(it)!=st.end()){
                    cnt++;
                    break;
                }
            }
            n++;
            // tokens.push_back(intermediate);
        }
        // int n=tokens.size();
        return n-cnt;
    }
};