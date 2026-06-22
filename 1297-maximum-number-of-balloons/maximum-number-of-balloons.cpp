class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0,a=0,l=0,n=0,o=0;
        for(auto it:text){
            if(it=='b'){
                b++;
            }else if(it=='a'){
                a++;
            }else if(it=='l'){
                l++;
            }else if(it=='n'){
                n++;
            }else if(it=='o'){
                o++;
            }
        }
        // cout<<b<<a<<l<<n<<o;
        o/=2;
        l/=2;
        return min({b,a,l,n,o});
    }
};