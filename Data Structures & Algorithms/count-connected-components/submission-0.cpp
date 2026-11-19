class Solution {
    private:
    void solve(int node, vector<vector<int>>& adj, vector<int>&vis){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                solve(it, adj, vis);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        vector<vector<int>> adj(n);

for(auto &it : edges){
    int u = it[0];
    int v = it[1];

    adj[u].push_back(v);
    adj[v].push_back(u);
}
        vector<int>vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                solve(i, adj, vis);
            }
        }
        return cnt;
    }
};
