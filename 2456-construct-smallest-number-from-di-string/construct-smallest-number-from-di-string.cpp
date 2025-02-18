class Solution {
public:
    bool check(string s,string pattern){
    int n=s.length();
    int m=pattern.length();
    for(int i=0;i<n;i++){
        if(pattern[i]=='I'){
            if(s[i]>s[i+1]){
                return false;
            }
        }else{
            if(s[i]<s[i+1]){
                return false;
            }
        }
    }
    return true;
}
string smallestNumber(string s){
    int n=s.size();
    string result;
    for(int i=1;i<=n+1;i++){
        result+=to_string(i);
    }
    while(!check(result,s)){
        next_permutation(result.begin(),result.end());
    }
    return result;
}
};