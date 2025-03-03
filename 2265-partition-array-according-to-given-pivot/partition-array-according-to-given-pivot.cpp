class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>less,more;
        int count=0;
        for(auto it:nums){
            if(it>pivot){
                more.push_back(it);
            }else if(it==pivot){
                count++;
            }else{
                less.push_back(it);
            }
        }
        for(int i=0;i<count;i++){
            less.push_back(pivot);
        }
        for(int i=0;i<more.size();i++){
            less.push_back(more[i]);
        }
        return less;
    }
};