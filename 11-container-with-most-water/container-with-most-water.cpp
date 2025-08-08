class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int ans=(j-i)*min(height[i],height[j]);
        while(i<j){
            if(height[i]>height[j]){
                j--;
            }else{
                i++;
            }
            ans=max(ans,(j-i)*min(height[i],height[j]));
        }
        return ans;
    }
};