class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=nums[0];
        int b=nums[1];
        int c=nums[2];
        if(c>=a+b)return "none";
        if(a==b){
            if(b==c){
                return "equilateral";
            }else{
                return "isosceles";
            }
        }else if(b==c){
            if(a==c)return "equilateral";
            else return "isosceles";
        }
        return "scalene";
    }
};