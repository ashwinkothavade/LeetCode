class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(pq.size()>1){
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            pq.push(first-second);
        }
        return pq.top();

    }
};