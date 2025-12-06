class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        unordered_map<int, vector<int>> adj;
        int e = edges.size();
        for(int i=0; i<e; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> qu;
        qu.push(src);
        int inf = 1e9;
        vector<int> dis(V, inf);
        dis[src] = 0;
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            for(auto it : adj[node]){
                if(dis[node] != inf){
                    if(dis[node] + 1 < dis[it]){
                        dis[it] = 1 + dis[node];
                        qu.push(it);
                    }
                }
            }
        }
        for(int i=0; i<V; i++){
            if(dis[i] == inf){
                dis[i] = -1;
            }
        }
        return dis;
    }
};
