class Solution {
    private:
    vector<string>ans;
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>>adj;
    void solve(string node){
        while(!adj[node].empty()){
            string nei = adj[node].top();
            adj[node].pop();
            solve(nei);
        }
        ans.push_back(node);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &it: tickets){
            string u = it[0];
            string v = it[1];
            adj[u].push(v);
        }
        solve("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
