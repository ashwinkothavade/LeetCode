class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n>0){
            int last=n%3;
            if(last==2)return false;
            n=n/3;
        }
        return true;
    }
};