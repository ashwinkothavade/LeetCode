class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        int xorr=0;
        for(auto it:derived){
            xorr^=it;
        }
        return xorr==0;
    }
};