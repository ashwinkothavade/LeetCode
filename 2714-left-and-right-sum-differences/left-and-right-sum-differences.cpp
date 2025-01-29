class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int leftsum = 0;
        int rightsum = 0;
        int t=0;
        for (int i = 0; i < nums.size(); i++) {
            rightsum += nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {

            int val = nums[i];
            rightsum -= nums[i];
            nums[i] = abs(leftsum - rightsum);

            leftsum += val;
        }
        return nums;
    }
};