class Solution {
    bool isincreasing(vector<int>&v){
        int n=v.size();
        for(int i=0;i<n-1;i++){
            if(v[i]>=v[i+1]){
                return false;
            }
        }
        return true;
    }
    bool isdecreasing(vector<int>&v){
        int n=v.size();
        for(int i=0;i<n-1;i++){
            if(v[i]<=v[i+1]){
                return false;
            }
        }
        return true;
    }

public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=i;j<n;j++){
                temp.push_back(nums[j]);
                if(isincreasing(temp))
                ans=max(ans,j-i+1);
                if(isdecreasing(temp))
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};