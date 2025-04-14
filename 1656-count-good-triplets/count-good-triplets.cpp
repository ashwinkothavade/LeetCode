class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int first=arr[i];
            for(int j=i+1;j<n;j++){
                int second=arr[j];
                for(int k=j+1;k<n;k++){
                    int third=arr[k];
                    if((abs(first-second)<=a)&&(abs(second-third)<=b)&&(abs(first-third)<=c)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};