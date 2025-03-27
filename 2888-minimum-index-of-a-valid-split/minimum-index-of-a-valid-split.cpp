class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        unordered_map<int,int>temp;
        int maxfre=0;
        int maxele=0;
        for(int i=0;i<n;i++){
            temp[nums[i]]++;
            if(temp[nums[i]]>maxfre){
                maxfre=temp[nums[i]];
                maxele=nums[i];
                int freinremainarray=mp[nums[i]]-maxfre;
                if(maxfre>(i+1)/2&&freinremainarray>(n-i-1)/2){
                    return i;
                }
            }
        }
        return -1;
    }
};