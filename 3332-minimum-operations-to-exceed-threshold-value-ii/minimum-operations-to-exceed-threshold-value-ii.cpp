class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(auto it:nums){
            pq.push(it);
        }
        int cnt=0;
        if(n==1)return 0;
        while(pq.top()<k){
            if(pq.size()>=2){
                long long num1=pq.top();
                pq.pop();
                long long num2=pq.top();
                pq.pop();
                pq.push(min(1LL*num1,1LL*num2)*2+max(1LL*num1,1LL*num2));
                cnt++;
            }
        }
        return cnt;
    }
};