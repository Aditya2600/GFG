class Solution {
    
  private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>> &edges){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto v : edges[node]){
            if(!vis[v]){
                if(dfs(v, vis, pathVis, edges)){
                    return true;
                }
            }
            else if(pathVis[v]){
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
    
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
        }
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, vis, pathVis, adj)){
                    return true;
                }
            }
            
        }
        return false;
    }
};