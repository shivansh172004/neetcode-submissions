class Solution {
    private:
    bool solve(vector<vector<int>>& adj, int node, vector<int>&vis, int par){
        vis[node] = 1;
        for(auto adjNode: adj[node]){
            if(!vis[adjNode]){
                if(solve(adj, adjNode, vis, node)){
                    return true;
                }
            }
                else if(adjNode != par) return true;
        }
        return false;
    } 
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // if undirected graph have cycle, then it is not a valid tree

        if(edges.size() != n - 1) return false;
        vector<vector<int>> adj(n);
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(solve(adj, i, vis, -1)){
                    return false;
                }
            }
        }
        return true;
    }
};
