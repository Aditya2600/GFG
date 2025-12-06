class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v, it[2]});
            adj[v].push_back({u, it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int edgeWeight = it.second;
                int adjNode = it.first;
                if(dist[adjNode] > dis + edgeWeight){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};