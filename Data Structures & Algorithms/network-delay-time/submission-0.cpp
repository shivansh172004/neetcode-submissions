class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //dijkstra algorithm
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &it : times){
    int u = it[0];
    int v = it[1];
    int w = it[2];

    adj[u].push_back({v, w});
}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int>dist(n+1, INT_MAX);
        int cnt = 0;
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dis > dist[node]) continue;
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgWt = it.second;
                if(dis + edgWt < dist[adjNode]){
                    dist[adjNode] = dis + edgWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == INT_MAX){
                 return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
