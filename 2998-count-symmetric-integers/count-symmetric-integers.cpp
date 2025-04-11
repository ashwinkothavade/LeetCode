class Solution {
    bool check(int num){
        int count=0;
        int t=num;
        int sumfirst=0;
        int sumtotal=0;
        while(t>0){
            sumtotal+=t%10;
            t=t/10;
            count++;
        }
        if(count%2==1)return false;
        count=count/2;
        int w=num;
        while(count>0){
            sumfirst+=w%10;
            w=w/10;
            count--;
        }
        return sumtotal-sumfirst==sumfirst;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
            if(check(i)){
                ans++;
            }
        }
        return ans;
    }
};