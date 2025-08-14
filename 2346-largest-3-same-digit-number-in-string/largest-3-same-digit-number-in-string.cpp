class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        char maxnumber='+';
        for(int i=0;i<n-2;i++){
            if(num[i]==num[i+1]&&num[i+1]==num[i+2]){
                maxnumber=max(maxnumber,num[i]);
            }
        }
        string ans="";
        ans=maxnumber;
        ans+=ans;
        ans+=maxnumber;
        return maxnumber>'+'?ans:"";
    }
};