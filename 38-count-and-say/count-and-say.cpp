
class Solution {
    public:
        string countAndSay(int n) {
            string base="11";
            if(n==1)return "1";
            if(n==2)return "11";
            for(int i=2;i<n;i++){
                string temp="";
                char consecutive='1';
                for(int j=1;j<base.size();j++){
                    if(base[j-1]==base[j]){
                        consecutive++;
                        // cout<<consecutive<<endl;
                    }else{
                        temp+=(char)consecutive;
                        // cout<<temp<<endl;
                        temp+=(char)base[j-1];
                        // cout<<temp<<endl;
                        consecutive='1';
                    }
                }
                temp+=(char)consecutive;
                temp+=(char)base[base.size()-1];
                base=temp;
            }
            return base;
        }
    };