class dsu {
public:
    vector<int> size, parent;

    dsu(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findparent(int node) {
        if (parent[node] == node) {
            return node;
        }
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
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<pair<int, int>>> adj(n);
        dsu ds(n);

        for (auto& it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
            ds.unionbysize(it[0], it[1]);
        }

        vector<int> cost(n, -1);
        for (auto& it : edges) {
            int root = ds.findparent(it[0]);
            if (cost[root] == -1) cost[root] = it[2];
            else cost[root] &= it[2];
        }

        vector<int> ans;
        for (auto& it : query) {
            int a = it[0], b = it[1];

            if (ds.findparent(a) != ds.findparent(b)) {
                ans.push_back(-1);
            } else {
                ans.push_back(cost[ds.findparent(a)]);
            }
        }
        return ans;
    }
};
