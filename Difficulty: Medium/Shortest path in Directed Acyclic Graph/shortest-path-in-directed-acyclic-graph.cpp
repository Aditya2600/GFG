// User function Template for C++
class Solution {
    private:
        void dfs(int node, unordered_map<int, vector<pair<int, int>>>& mp, vector<int>& vis, stack<int>& st){
            vis[node] = 1;
            for(auto& p : mp[node]){
                int neigh = p.first;
                if(!vis[neigh]){
                    dfs(neigh, mp, vis, st);
                    
                }
            }
            st.push(node);
        }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vector<pair<int, int>>> mp;
        for(int i=0; i<E; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            mp[u].push_back({v, w});
        }
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, mp, vis, st);
            }
        }
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;

        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(dist[node] != INT_MAX){
                for(auto &p : mp[node]){
                    int neigh = p.first;
                    int wt = p.second;
                    if(dist[node] + wt < dist[neigh]){
                        dist[neigh] = dist[node] + wt;
                    }
                }
            }
        }
        for(int i=0; i < V; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        return dist;
    }
};
