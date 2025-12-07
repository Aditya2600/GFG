class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<int> dist(n+1, 1e9);
        dist[1] = 0;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        pq.push({dist[1], 1});
        vector<int> par(n+1);
        for(int i=1; i<=n; i++){
            par[i] = i;
        }
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgWt = it.second;
                if(dist[adjNode] > dis + edgWt){
                    dist[adjNode] = dis + edgWt;
                    par[adjNode] = node;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        if(dist[n] == 1e9){
            return {-1};
        }
        int node = n;
        vector<int> path;
        while(par[node] != node){
            path.push_back(node);
            node = par[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        vector<int> ans;
        ans.push_back(dist[n]);
        for(auto x : path) ans.push_back(x);
        return ans;
    }
};