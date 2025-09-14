class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int>st(nums.begin(),nums.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it:st){
            pq.push(it);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};