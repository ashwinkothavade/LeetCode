class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<bool>vis(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!vis[j]){
                    if(fruits[i]<=baskets[j]){
                        cnt++;
                        vis[j]=true;
                        break;
                    }
                }
            }
        }
        return n-cnt;
    }
};