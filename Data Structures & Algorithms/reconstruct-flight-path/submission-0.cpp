class Solution {
    vector<string>ans;
    unordered_map<string, multiset<string>>adj;
    private:
    void solve(string airport){
        while(!adj[airport].empty()){
            string next = *adj[airport].begin();
            adj[airport].erase(adj[airport].begin());
            solve(next);
        }
         ans.push_back(airport);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        for (auto &ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }
        solve("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
