class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>answer(n,0);
        for(int i=0;i<n;i++){
            int curr=0;
                for(int j=0;j<i;j++){
                    if(boxes[j]=='1')
                    curr+=abs(i-j);

                }
                for(int j=i+1;j<n;j++){
                    if(boxes[j]=='1')
                    curr+=abs(i-j);
                }
            answer[i]=curr;
        }
        return answer;
    }
};