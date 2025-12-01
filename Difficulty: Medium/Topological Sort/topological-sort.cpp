// class Solution {
//     private:
//         void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st){
//             vis[node] = 1;
//             for(auto it : adj[node]){
//                 if(!vis[it]){
//                     dfs(it, vis, adj, st);
//                 }
//             }
//             st.push(node);
//         }
//   public:
//     vector<int> topoSort(int V, vector<vector<int>>& edges) {
//         vector<int> ans;
//         vector<int> vis(V, 0);
//         vector<vector<int>> adj(V);
//         for(int i=0;i<edges.size();i++){
//             int u = edges[i][0];
//             int v = edges[i][1];
//             adj[u].push_back(v);
//         }
//         stack<int> st;
//         for(int i=0; i<V; i++){
//             if(!vis[i]){
//                 dfs(i, vis, adj, st);
//             }
//         }
//         while(!st.empty()){
//             ans.push_back(st.top());
//             st.pop();
//         }
//         return ans;
//     }
// };

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int> qu;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                qu.push(i);
            }
        }
        
        vector<int> topo;
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            topo.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    qu.push(it);
                }
            }
        }
        return topo;
    }
};