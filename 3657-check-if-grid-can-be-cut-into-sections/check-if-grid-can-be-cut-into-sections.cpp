class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>>xcoor,ycoor;
        for(auto it:rectangles){
            xcoor.push_back({it[0],it[2]});
            ycoor.push_back({it[1],it[3]});
        }
        sort(xcoor.begin(),xcoor.end());
        sort(ycoor.begin(),ycoor.end());
        int xcount=0;
        int ycount=0;
        vector<pair<int,int>>xcc,ycc;
        // xcc.push_back(xcoor[0]);
        // ycc.push_back(ycoor[0]);
        // for(int i=1;i<xcoor.size();i++){
        //     if(xcc.back().first==xcoor[i].first){
        //         xcc.back().second=max(xcc.back().second,xcoor[i].second);
        //     }else{
        //         xcc.push_back(xcoor[i]);
        //     }
        //     if(ycc.back().first==ycoor[i].first){
        //         ycc.back().second=max(ycc.back().second,ycoor[i].second);
        //     }else{
        //         ycc.push_back(ycoor[i]);
        //     }
        // }
        int maxiright=xcoor[0].second;
        for(int i=0;i<xcoor.size()-1;i++){
            if(xcoor[i].second<=xcoor[i+1].first&&maxiright<=xcoor[i+1].first){
                xcount++;
                maxiright=max(maxiright,xcoor[i+1].second);
            }else{
                maxiright=max(maxiright,xcoor[i+1].second);
            }
        }
        int maxiup=ycoor[0].second;
        for(int i=0;i<ycoor.size()-1;i++){
            if(ycoor[i].second<=ycoor[i+1].first&&maxiup<=ycoor[i+1].first){
                ycount++;
                maxiup=max(maxiup,ycoor[i+1].second);
            }else{
                maxiup=max(maxiup,ycoor[i+1].second);
            }
        } 
        return xcount>=2||ycount>=2;
    }
};