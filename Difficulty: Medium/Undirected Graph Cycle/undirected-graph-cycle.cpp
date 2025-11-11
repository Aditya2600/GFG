// class Solution {
//   public:
//     bool detect(int src, vector<vector<int>>& adj, vector<int>& vis){
//         queue<pair<int, int>> qu;
//         qu.push({src, -1});
//         vis[src] = 1;
//         while(!qu.empty()){
//             auto curr = qu.front();
//             qu.pop();
//             int node = curr.first;
//             int parent = curr.second;
//             for(auto adjN : adj[node]){
//                 if(!vis[adjN]){
//                     qu.push({adjN, node});
//                     vis[adjN] = 1;
//                 }
//                 else if(parent != adjN){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
//     bool isCycle(int V, vector<vector<int>>& edges) {
//         // Code here
//         vector<int> vis(V, 0);
//         vector<vector<int>> adj(V);
//         for(auto it : edges){
//             adj[it[0]].push_back(it[1]);
//             adj[it[1]].push_back(it[0]);
//         }
//         for(int i=0; i<V; i++){
//             if(!vis[i]){
//                 if(detect(i, adj, vis)){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

class Solution {
  public:
    bool detect(int src, int par, vector<vector<int>>& adj, vector<int>& vis){
        vis[src] = 1;
        for(auto &v : adj[src]){
            if(v == par) continue;
             if(vis[v]) return true;
             
             if(detect(v, src, adj, vis)){
                 return true;
             }
        }
        return false; 
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> vis(V, 0);
        vector<vector<int>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(detect(i, -1, adj, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};