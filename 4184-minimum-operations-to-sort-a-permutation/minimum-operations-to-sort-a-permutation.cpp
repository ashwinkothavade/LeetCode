class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        for(int i=0;i<n;i++) temp.push_back(i);
        if(temp==nums) return 0;
        reverse(temp.begin(),temp.end()) ;
        if(temp==nums) return 1;
        int l1=1,l2=0;
        int i=1;bool inc=false;
        if(nums[1]==(nums[0]+1)){
            inc=true;
            while(i<n&&nums[i]==nums[i-1]+1){
                l1++;
                i++;
            }
        }
        else if(nums[1]==(nums[0]-1)){
            inc=false;
            while(i<n&&nums[i]==nums[i-1]-1){
                l1++;
                i++;
            }
        }
        else{
            if(nums[2]>nums[1]) inc=true;
            else inc=false;
        }
        l2++;i++;
        if(inc==true){
            while(i<nums.size()&&nums[i]==(nums[i-1]+1)){
                inc=true;
                l2++;
                i++;
            }
        }
        else if(inc==false){
            while(i<n&&nums[i]==(nums[i-1]-1)){
                inc=false;
                l2++;
                i++;
            }
        }
        if((l1+l2)!=nums.size()) return -1;
        int op=INT_MAX;
        cout<<l1<<l2;
        if(inc==true) {
            op=min(op,l1);
            op=min(op,l2+2);
        }
        else{
            op=min(op,l1+1);
            op=min(op,l2+1);
        }
        return op;
    }
};