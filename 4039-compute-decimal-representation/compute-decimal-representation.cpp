class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>ans;
        int cnt=0;
        while(n>0){
            int last=n%10;
            int num=pow(10,cnt)*last;
            if(num!=0)
            ans.push_back(num);
            n/=10;
            cnt++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};