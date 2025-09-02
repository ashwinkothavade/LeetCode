class Solution {
    bool pred(vector<int>&piles,int &mid,int &h){
        int n=piles.size();
        //find if koko can eat all the banana within h hours with the speed of mid
        int time=0;
        for(int i=0;i<n;i++){
            time+=(piles[i]+mid-1)/mid;
        }
        return time<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=high+(low-high)/2;
            if(pred(piles,mid,h)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};