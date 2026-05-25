class Solution {
public:
    int passwordStrength(string password) {
        int count=0;
        unordered_set<char>st;
       for(auto it:password){
        if(st.find(it)==st.end()){
            if(it>=97&&it<=122){
                count+=1;
            }else if(it>=65&&it<=90){
                count+=2;
            }else if(it>=48 &&it<=57){
                count+=3;
            }else{
                count+=5;
            }
            st.insert(it);
        }
       }
       return count;
    }
};