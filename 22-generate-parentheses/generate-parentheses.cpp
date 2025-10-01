class Solution {
    void helper(vector<string>&ans,string s,int open,int close,int n){
        if(s.size()==2*n){
            ans.push_back(s);
        }
        if(open<n){
            helper(ans,s+'(',open+1,close,n);
        }
        if(open>close){
            helper(ans,s+')',open,close+1,n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        helper(ans,s,0,0,n);
        return ans;
    }
};