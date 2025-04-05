class Solution {
    void helper(vector<vector<int>>&ans,vector<int>&nums,vector<int>&op,int index){
        if(index==nums.size()){
            ans.push_back(op);
            return;
        }
        op.push_back(nums[index]);
        helper(ans,nums,op,index+1);
        op.pop_back();
        helper(ans,nums,op,index+1);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>op;
        helper(ans,nums,op,0);
        int finalans=0;
        for(int i=0;i<ans.size();i++){
            int xorr=0;
            for(int j=0;j<ans[i].size();j++){
                xorr^=ans[i][j];
            }
            finalans+=xorr;
        }
        return finalans;
    }
};