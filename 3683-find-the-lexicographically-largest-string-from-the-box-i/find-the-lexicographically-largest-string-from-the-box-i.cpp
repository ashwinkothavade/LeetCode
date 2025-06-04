class Solution {
public:
    string answerString(string s, int numFriends) {
        //unordered_set<string>st;
        int n=s.size();
        if(numFriends==1)return s;
        //the maxlenght of the string allowed will be n-numFriends+1;
        int maxplen=n-numFriends+1;
        string largest="a";
        for(int i=0;i<n;i++){
            if(s.substr(i,maxplen)>largest){
                largest=s.substr(i,maxplen);
            }
        }
        return largest;   
    }
};