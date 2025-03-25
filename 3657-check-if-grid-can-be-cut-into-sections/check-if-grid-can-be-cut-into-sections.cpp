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
        // map<int,int>mpx,mpy;
        // for(int i=0;i>xcoor.size();i++){
        //     mpx[xcoor[i].first]=max(mpx[xcoor[i].first],xcoor[i].second);
        //     mpy[ycoor[i].first]=max(mpy[ycoor[i].first],ycoor[i].second);
        // }
        vector<pair<int,int>>xcc,ycc;
        xcc.push_back(xcoor[0]);
        ycc.push_back(ycoor[0]);
        for(int i=1;i<xcoor.size();i++){
            if(xcc.back().first==xcoor[i].first){
                xcc.back().second=max(xcc.back().second,xcoor[i].second);
            }else{
                xcc.push_back(xcoor[i]);
            }
            if(ycc.back().first==ycoor[i].first){
                ycc.back().second=max(ycc.back().second,ycoor[i].second);
            }else{
                ycc.push_back(ycoor[i]);
            }
        }
        int maxiright=xcc[0].second;
        for(int i=0;i<xcc.size()-1;i++){
            cout<<xcc[i].first<<" "<<xcc[i].second<<endl;
            if(xcc[i].second<=xcc[i+1].first&&maxiright<=xcc[i+1].first){
                xcount++;
                maxiright=max(maxiright,xcc[i+1].second);
            }else{
                maxiright=max(maxiright,xcc[i+1].second);
            }
        }
        cout<<xcc[xcc.size()-1].first<<" "<<xcc[xcc.size()-1].second<<endl;
        cout<<endl;
        int maxiup=ycc[0].second;
        for(int i=0;i<ycc.size()-1;i++){
            cout<<ycc[i].first<<" "<<ycc[i].second<<endl;
            if(ycc[i].second<=ycc[i+1].first&&maxiup<=ycc[i+1].first){
                ycount++;
                maxiup=max(maxiup,ycc[i+1].second);
            }else{
                maxiup=max(maxiup,ycc[i+1].second);
            }
        }
        cout<<ycc[ycc.size()-1].first<<" "<<ycc[ycc.size()-1].second<<endl;
        cout<<endl;
        cout<<xcount<<" "<<ycount<<endl;  
        return xcount>=2||ycount>=2;
    }
};