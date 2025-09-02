class Solution {
    bool pred(vector<int>&bloomDay,int mid,int m,int k){
        int n=bloomDay.size();
        //we have to find how many bouquets will be formed on the day ==mid;
        int cnt=0;
        int bq=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }else{
                bq+=cnt/k;
                cnt=0;
            }
        }
        bq+=cnt/k;
        return bq>=m;

    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*(long long)k>n)return -1;
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=high+(low-high)/2;
            if(pred(bloomDay,mid,m,k)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};