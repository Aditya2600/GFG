class Solution {
  public:
  typedef pair<int, int> p;
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vector<pair<int, int>>> adj;
        int e = edges.size();
        for(int i=0; i<e; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, 0});
        vector<bool> inMST(V, false);
        int sum = 0;
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(inMST[node] == true){
                continue;
            }
            inMST[node] = true;
            sum += wt;
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjNodeWt = it.second;
                
                if(!inMST[adjNode]){
                    pq.push({adjNodeWt, adjNode});
                }
            }
        }
        return sum;
    }
};