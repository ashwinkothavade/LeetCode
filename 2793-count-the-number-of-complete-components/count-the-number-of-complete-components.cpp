#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;
    
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int findparent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findparent(parent[node]); 
    }
    
    void unionbysize(int u, int v) {
        int ulp_u = findparent(u);
        int ulp_v = findparent(v);
        if (ulp_u == ulp_v) return;
        
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU ds(n);

        for (auto& it : edges) {
            ds.unionbysize(it[0], it[1]);
        }

        unordered_map<int, pair<int, unordered_set<int>>> mp;

        for (auto& it : edges) {
            int par = ds.findparent(it[0]);
            mp[par].first++;  
            mp[par].second.insert(it[0]);
            mp[par].second.insert(it[1]);
        }
        for(auto it:mp){
            cout<<it.first<<endl;
            cout<<it.second.first<<endl;
            for(auto item:it.second.second){
                cout<<item<<" ";
            }
            cout<<endl;
        }
        int ans = 0;
        int finalnodecnt=0;
        for (auto& it : mp) {
            int numberOfEdges = it.second.first;
            int nodeCount = it.second.second.size();
            finalnodecnt+=nodeCount;
            if (numberOfEdges == (nodeCount * (nodeCount - 1) / 2)) {
                ans++;
            }
        }
        ans+=(n-finalnodecnt);
        return ans;
    }
};
