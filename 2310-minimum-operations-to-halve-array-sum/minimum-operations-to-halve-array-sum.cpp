class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> q;
        double starting_sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            starting_sum += nums[i];
            q.push(nums[i]);
        }
        double sum = starting_sum;
        int ans = 0;
        while(sum > starting_sum/2){
            double value = q.top()/2;
            sum -= value;
            q.pop();
            q.push(value);
            ans++;
        }
        return ans;
    }
};