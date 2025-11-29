class Solution {
    private:
        void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st){
            vis[node] = 1;
            for(auto it : adj[node]){
                if(!vis[it]){
                    dfs(it, vis, adj, st);
                }
            }
            st.push(node);
        }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> vis(V, 0);
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};