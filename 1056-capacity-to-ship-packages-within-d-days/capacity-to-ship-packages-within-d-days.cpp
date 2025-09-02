class Solution {
    bool pred(vector<int>&nums,int mid,int days){
        int n=nums.size();
        int d=1;
        int w=0;
        for(int i=0;i<n;i++){
            if(w+nums[i]>mid){
                d++;
                w=nums[i];
            }else{
                w+=nums[i];
            }
        }

        return d<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=high+(low-high)/2;
            if(pred(weights,mid,days))high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};