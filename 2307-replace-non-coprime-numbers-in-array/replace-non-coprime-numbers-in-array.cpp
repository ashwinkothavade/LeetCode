class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int nums1=nums[i];
            while(!st.empty()){
                int top=st.top();
                int g=__gcd(top,nums1);
                if(g==1){
                    break;
                }
                st.pop();
                long long m=(long long)top/g*nums1;
                nums1=(int)m;
            }
            st.push(nums1);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};