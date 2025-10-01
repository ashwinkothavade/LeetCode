class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>v;
        int n=position.size();
        for(int i=0;i<n;i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.rbegin(),v.rend());
        stack<double>st;
        for(auto it:v){
            int p=it.first;
            int s=it.second;
            double t=(double)(target-p)/s;
            if(st.empty()||t>st.top()){
                st.push(t);
            }
        }
        return st.size();

    }
};