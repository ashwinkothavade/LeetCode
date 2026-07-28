class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                el=nums[i];
                cnt+=1;
            }else if(el==nums[i]){
                cnt++;
            }else {
                cnt--;
            }
        }
        int t=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==el){
                t++;
            }
        }
        if(t>nums.size()/2){
            return el;
        }
        return -1;
    }
};