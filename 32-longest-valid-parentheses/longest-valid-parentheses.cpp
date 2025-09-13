class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int ans=0;
        for(int i=0;i<s.size();i++){
            auto it=s[i];
            if(it=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    ans=max(ans,i-st.top());
                }
            }
        }
        return ans;
    }
};