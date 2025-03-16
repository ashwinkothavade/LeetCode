class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>st;
        int sum=0;
        int maxneg=INT_MIN;
        for(auto it:nums){
            if(it>0&&st.find(it)==st.end()){
                st.insert(it);
                sum+=it;
            }else{
                maxneg=max(maxneg,it);
            }
        }
        if(st.size()==0)return maxneg;
        return sum;
    }
};