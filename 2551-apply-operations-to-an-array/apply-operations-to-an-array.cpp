class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
        }
        int i=0;
        for(int j=0;j<n;j++){
            if(nums[j]!=0)
            nums[i++]=nums[j];
        }
        for(int j=i;j<n;j++){
            nums[j]=0;
        }
        return nums;
        // int zeroes=0;
        // vector<int>temp;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==0){
        //         zeroes++;
        //     }else{
        //         temp.push_back(nums[i]);
        //     }
        // }
        // for(int i=0;i<zeroes;i++){
        //     temp.push_back(0);
        // }
        // return temp;       
    }
};