class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<int, vector<int>> diagMap;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                diagMap[i - j].push_back(matrix[i][j]);
            }
        }
        // for(auto it:diagMap){
        //     cout<<it.first<<endl;
        //     for(auto i:it.second){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl<<endl;
        // }
        for (auto& [key, vec] : diagMap){
            if(key<0)
            sort(vec.begin(), vec.end());
            else{
                sort(vec.rbegin(), vec.rend());
            }        
        }

        // for(auto it:diagMap){
        //     cout<<it.first<<endl;
        //     for(auto i:it.second){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl<<endl;
        // }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) {
                matrix[i][j] = diagMap[i - j].front();
                diagMap[i - j].erase(diagMap[i - j].begin());
            }
        }
        return matrix;
    }
};