
class Solution {
private:
    bool solve(int node, int target,
               vector<vector<int>>& adj,
               vector<int>& vis) {

        if(node == target) return true;

        vis[node] = 1;

        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(solve(it, target, adj, vis)) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<vector<int>> adj(n + 1);

        for(auto &it : edges) {

            int u = it[0];
            int v = it[1];

            vector<int> vis(n + 1, 0);

            // Check if u and v are already connected
            if(solve(u, v, adj, vis)) {
                return {u, v};
            }

            // Add edge only if it doesn't create a cycle
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};
