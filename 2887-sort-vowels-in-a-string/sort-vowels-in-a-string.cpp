class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();
        vector<char>vowels;
        set<char>st={'a','e','i','o','u','A','E','I','O','U'};
        for(auto c:s){
            if(st.find(c)!=st.end()){
                vowels.push_back(c);
            }
        }
        sort(vowels.begin(),vowels.end());
        int t=0;
        for(int i=0;i<n;i++){
            if(st.find(s[i])!=st.end()){
                s[i]=vowels[t];
                t++;
            }
        }
        return s;
    }
};