class TaskManager {
    unordered_map<int,pair<int,int>>mp;//{taskid,{userid,priority}}
    set<pair<int,int>>st;//{priority,taskid}
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &it:tasks){
            int userid=it[0];
            int taskid=it[1];
            int priority=it[2];
            add(userid,taskid,priority);
        }
    }
    
    void add(int userid, int taskid, int priority) {
        mp[taskid]={userid,priority};
        st.insert({priority,taskid});
    }
    
    void edit(int taskid, int newp) {
        auto [userid,oldp]=mp[taskid];
        st.erase({oldp,taskid});
        st.insert({newp,taskid});
        mp[taskid]={userid,newp};
    }
    
    void rmv(int taskid) {
        auto [userid,priority]=mp[taskid];
        st.erase({priority,taskid});
        mp.erase(taskid);
    }
    
    int execTop() {
        if(st.empty()){
            return -1;
        }
        auto it=st.rbegin();
        int p=it->first,taskid=it->second;
        int userid=mp[taskid].first;
        rmv(taskid);
        return userid;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */